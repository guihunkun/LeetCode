class Solution 
{
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) 
    {
        priority_queue<int> p;                                                    // 利润 大根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> c;   // 资本 小根堆
        for(int i = 0; i < Capital.size(); i++) 
        {
            c.emplace(make_pair(Capital[i], Profits[i]));
        }

        for(int i = 0; i < k; i++) 
        {
            while (!c.empty() && c.top().first <= W) 
            {  // 资本小于等于W的项目，存入利润大根堆
                p.emplace(c.top().second);
                c.pop();
            }
            if(p.empty()) 
                break;
            W += p.top();                         // 每次选利润最大的
            p.pop();
        }
        return W;
    }
};
