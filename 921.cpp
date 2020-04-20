/*
class Solution 
{
public:
    int minAddToMakeValid(string S) 
    {
        int l = 0, r = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '(')
            {
                l++;
            }
            if(S[i] == ')')
            {
                if(l > 0)
                {
                    l--;
                }
                else
                {
                    r--;
                }
            }
        }
        return abs(r-l);

    }
};
*/
class Solution 
{
public:
    int minAddToMakeValid(string S) 
    {
        int l = 0, r = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '(')
            {
                l++;
            }
            if(S[i] == ')')
            {
                if(l > 0)
                {
                    l--;
                }
                else
                {
                    r++;
                }
            }
        }
        return r+l;

    }
};
