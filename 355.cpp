class Twitter 
{
public:
    /** Initialize your data structure here. */
    Twitter() 
    {
        fIndex = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        fMapTweet[userId].push_back( make_pair(fIndex++, tweetId) );//升序排列
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        //遍历每一个推特，维护一个10个元素的最小堆
        int total = 10;
        priority_queue<TweetPair, vector<TweetPair>, greater<TweetPair> >  que;

        SetFollow& setFollow = fMapFollow[userId];//获取用户的所有关注
        setFollow.insert(userId);//关注自己，可以一起处理

        for(auto id : setFollow)
        {
            VecTweet& vecTweet = fMapTweet[id];//每一个关注用户的推特
            int num = 0;
            //10 * lg(10) * m,m为关注的个数
            for(int i = vecTweet.size() - 1; i >= 0 && num <= total; i--)//反向遍历，从大到小；且不超过10条
            {
                if(que.size() < total)
                    que.push(vecTweet[i]);
                else
                {
                    if(que.top() > vecTweet[i])//最大值都不满足，则不用继续判断了
                        break;
                    else
                    {
                        //用当前值替代堆顶元素
                        que.pop();
                        que.push(vecTweet[i]);
                    } 
                }
                num++;
            }
        }

        //10 * log(10);
        vector<int> vec;
        while(!que.empty())
        {
           vec.push_back(que.top().second);
           que.pop(); 
        }

        std::reverse(vec.begin(), vec.end());//o(n)
        return vec;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        fMapFollow[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        if(fMapFollow.count(followerId) > 0)
            fMapFollow[followerId].erase(followeeId);
    }
protected:
    typedef pair<long long, int> TweetPair;
    typedef unordered_set<int> SetFollow;//每个用户的关注信息
    typedef vector<TweetPair> VecTweet;//每个用户的推特信息
    unordered_map<int, SetFollow> fMapFollow;//以用户id为key,以关注信息为val
    unordered_map<int, VecTweet> fMapTweet;//以用户id为key,以推特信息为val
    unsigned long long fIndex;//用来表示推特的发表次序
};
