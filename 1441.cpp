class Solution 
{
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        int nextPush = 1;   // 下一个push的元素   
        for(int i = 0; i < target.size(); ++i)
        {
            while(nextPush<target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                nextPush++;
            }
            ans.push_back("Push");
            nextPush++;
        }
        return ans;
    }
};
