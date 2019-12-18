class Solution
{
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        vector<pair<int, int>> rec;
        for(int i = 0; i < difficulty.size(); i++) 
        {
            rec.push_back(make_pair(difficulty[i], profit[i]));
        }  
        sort(rec.begin(), rec.end());
        int res = 0;
        int j = 0;
        int maxpro = 0;
        sort(worker.begin(), worker.end());
        for(int i = 0; i < worker.size(); i++)
        {
            for(; j < rec.size(); j++)
            {
                if(worker[i] >= rec[j].first)
                {
                    maxpro = max(maxpro, rec[j].second);
                }
                else
                    break;
            }
            res += maxpro;
        }
        return res;
    }
};
