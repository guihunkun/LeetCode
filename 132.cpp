class Solution 
{
public:
    int minCut(string s) 
    {
        int len=s.length();
        // 状态定义：dp[i]：前缀子串 s[0:i] （包括索引 i 处的字符）符合要求的最少分割次数
        int dp[len];
        // 1 个字符最多分割 0 次；
        // 2 个字符最多分割 1 次；
        // 3 个字符最多分割 2 次
        // 初始化的时候，设置成为这个最多分割次数
        for(int i=0;i<len;i++)
        {
            dp[i]=i;
        }
        /*
          创建二维数组用于记录子串s[a:b]是否为回文串，
          且一开始全部初始化为false（可以发现a<=b）
        */
        vector<vector<bool>> checkPalindrome(len, vector<bool>(len, false));
        //根据所给的字符串s，遍历，记录子串s[a:b]是否为回文串
        for(int right=0;right<len;right++)
        {
            for(int left=0;left<=right;left++)
            {
                if(s[left]==s[right] && (right-left<=2 || checkPalindrome[left+1][right-1]))
                { // "right-left<=2" 和 "checkPalindrome[left+1][right-1]"位置不可换
                    checkPalindrome[left][right]=true;
                }
            }
        }

        // 状态转移方程：
        // dp[i] = min(dp[j] + 1 if s[j + 1: i] 是回文 for j in range(i))
        for(int i=0;i<len;i++)
        {
            if(checkPalindrome[0][i]) {
                dp[i]=0;
                continue;
            }
            for(int j=0;j<i;j++)
            {
                if(checkPalindrome[j+1][i]) {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[len-1];
    }
};


