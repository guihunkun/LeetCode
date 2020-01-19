class Solution 
{
public:
    char upper(char c) 
    {
        if(c >= 'a' && c <= 'z')
            return c - 'a' + 'A';
        return c;
    }
    string licenseKeyFormatting(string S, int K) 
    {
        string res;
        int count = 0;
        for(int i = S.size() - 1; i >= 0; --i) 
        {
            if(S[i] == '-') 
            {
                continue;
            }
            res += upper(S[i]);
            if(++count % K == 0) 
            {
                res += '-';
            }
        }
        while(!res.empty() && res.back() == '-')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
