class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char, int> rec;
        int res = 0;
        int l = 0, r = 0;
        while(r < s.size())
        {
            if(rec.find(s[r]) != rec.end())
            {
                l = max(l , rec[s[r]] + 1);
            }
            rec[s[r++]] = r;
            res = max(r-l, res);
        }
        return res;
    }
};

