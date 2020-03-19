class Solution 
{
public:
    int strongPasswordChecker(string s) 
    {
        int n = s.size();
        int missed = 0;
        int cnt[3] = {1, 1, 1};
        int exceedsTimes = 0;
        int exceeds[4] = {0};
        int loopvar[4][3] = {{21, 0, 1}, {22, 1, 2}, {23, 2, 3}, {23, 3, 3}};
        for(int i = 0; i < n; i++) 
        {
            islower(s[i]) ? cnt[0] = 0 : 0;
            isupper(s[i]) ? cnt[1] = 0 : 0;
            isdigit(s[i]) ? cnt[2] = 0 : 0;
        }
        missed = cnt[0] + cnt[1] + cnt[2];
        s.push_back(s[n - 1] > 10 ? s[n - 1] - 1 : s[n - 1] + 1);
        for(int i = 1, cnt = 1; i <= n; i++, cnt++) 
        {
            if(s[i] != s[i - 1]) 
            {
                if(cnt >= 3) 
                {
                    exceedsTimes += cnt / 3;
                    exceeds[cnt % 3]++;
                    exceeds[3] += cnt / 3 - 1;
                }
                cnt = 0;
            }
        }
        if(n <= 20) 
        {
            int shortage = max(6, n) - n;
            return max({missed, shortage, exceedsTimes});
        }
        for(auto& e : loopvar) 
        {
            while(n >= e[0] && exceeds[e[1]] > 0) 
            {
                n -= e[2];
                exceeds[e[1]]--;
                exceedsTimes--;
            }
        };
        return s.size() - 21 + max(missed, exceedsTimes);
    }
};
