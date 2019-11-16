class Solution
{
public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        if(N == 1)
            return 1;
        vector<int> record(N+1, 0);
        for(int i = 0; i < trust.size(); i++)
        {
            record[trust[i][0]]--;
            record[trust[i][1]]++;
        }
        for(int i = 1; i < record.size(); i++)
        {
            if(record[i] == N-1)
                return i;
        }
        return -1;
    }
};
