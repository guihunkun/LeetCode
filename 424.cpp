/*
class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.length();
        if (n == 0) 
            return 0;
        int cnt[26] = {0};
        int maxCount = 0, prev = 0;
        for (int i = 0; i < n; i++) 
        {
            cnt[s[i]-'A']++;
            maxCount = max(maxCount, cnt[s[i]-'A']);
            if (maxCount + k < i - prev + 1) 
            {
                cnt[s[prev]-'A']--;
                prev++;
            }
        }
        return n - prev;
    }
};
*/
class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        if(s.size() <= k)
            return s.size();
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); i++) 
        {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
};
