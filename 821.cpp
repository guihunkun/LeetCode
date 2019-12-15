class Solution 
{
public:
    vector<int> shortestToChar(string S, char C) 
    {
        vector<int> res(S.size(), 0);
        int prev = INT_MIN/2;
        for(int i = 0; i < S.size(); ++i)
        {
            if(S[i] == C)
                prev = i;
            res[i] = i - prev;
        }
        prev = INT_MAX/2;
        for(int i = S.size() - 1; i >= 0; --i)
        {
            if(S[i] == C)
                prev = i;
            res[i] = min(res[i], prev - i);
        }
        return res;
    }
};
