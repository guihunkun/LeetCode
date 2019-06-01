class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        int lower[26];
        int upper[26];
        bool flag = false;
        int res = 0;
        for(int i =0; i < 26; i++)
        {
            lower[i] = 0;
            upper[i] = 0;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                lower[s[i] - 'a']++;
            if(s[i] >= 'A' && s[i] <= 'Z')
                upper[s[i] - 'A']++;
        }
        for(int i = 0; i < 26; i++)
        {
            res += lower[i] / 2 * 2;
            if(res % 2 == 0 && lower[i] % 2 == 1)
                res++;
            res += upper[i] / 2 * 2;
            if(res % 2 == 0 && upper[i] % 2 == 1)
                res++;
        }
        return res;
    }
};
