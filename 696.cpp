/*
class Solution 
{
public:
    int countBinarySubstrings(string s) 
    {
        int prev = 0;
        int curr = 1;
        int res = 0;
        for(int i = 1; i < s.size(); ++i) 
        {
            if(s[i] == s[i - 1]) 
            {
                ++curr;
            } 
            else 
            {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        res += min(prev, curr);
        return res;
    }
};
*/
class Solution 
{
public:
    int countBinarySubstrings(string s) 
    {
        int res = 0;
        vector<int> rec;
        int cur = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i-1])
            {
                cur++;
            }
            else
            {
                rec.push_back(cur);
                cur = 1;
            }
        }
        rec.push_back(cur);
        for(int i = 1; i < rec.size(); i++)
        {
            res += min(rec[i-1], rec[i]);
        }
        return res;
    }
};

