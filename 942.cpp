class Solution 
{
public:
    vector<int> diStringMatch(string S) 
    {
        vector<int> res(S.size() + 1, 0);
        int left = 0, right = S.size();
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == 'I')
                res[i] = left++;
            else
                res[i] = right--;
        }
        res[S.size()] = left;
        return res;
    }
};
