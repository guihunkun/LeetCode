class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return helper(s, dp, 0, n);
    }
private:
    int helper(string& str, vector<vector<int>>& dp, int s, int e) {
        if (s >= e) return 0;
        if (dp[s][e]) return dp[s][e];
        // 处理 str[s] 的首尾字符
        // 注意范围是左闭右开 [s,e) [l,r)
        int l = s, r = e;
        while (l < e && str[l] == str[s]) l++;
        while (r > l && str[r-1] == str[s]) r--;
        dp[s][e] = 1+helper(str, dp, l, r);
        for (int i = l; i < r; i++) {
            if (str[i] == str[s]) {
                dp[s][e] = min(dp[s][e], helper(str,dp,l,i)+helper(str,dp,i,r));
                while (i < e && str[i] == str[s]) i++;
            }   
        }
        return dp[s][e];
    }
};
