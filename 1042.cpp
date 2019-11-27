class Solution 
{
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
    {
        vector<vector<int>> record(N);
        for(auto x : paths)
            record[max(x[0],x[1])-1].push_back(min(x[0],x[1])-1);
        vector<int> res(N,1); 
        for (int i = 1; i < N; i++) 
        {
            set<int> flower{ 1,2,3,4 };
            for (int j = 0; j < record[i].size(); j++)
                flower.erase(res[record[i][j]]);
            res[i] = *flower.begin();
        }
    return res;
    }
};
