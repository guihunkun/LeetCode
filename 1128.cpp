class Solution 
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        unordered_map<string, int> rec;
        int res = 0;
        for(auto dominoe : dominoes)
        {
            int a = dominoe[0], b = dominoe[1];
            if(a > b) { 
                swap(a,b);
            }
            string key = to_string(a) + to_string(b);
            rec[key]++;
        }
        for(auto it : rec)
        {
            res += (it.second-1)*it.second/2;
        }
        return res;
    }
};
