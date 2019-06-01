class Solution
{
public:
    char findTheDifference(string s, string t) 
    {
        if(s.size() == 0)
            return t[0];
        if(t.size() == 0)
            return s[0];
        char c = 0;
        for(int i= 0; i < t.size(); i++)
            c ^= t[i];
        for(int i= 0; i < s.size(); i++)
            c ^= s[i];
        return c;
    }
};
