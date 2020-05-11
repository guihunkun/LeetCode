class Solution {
public:
    //本题类似于最长公共子序列的问题，所以用动态规划
    int dp[510][510];//表示以word1的第i个结尾和以word2的第j个结尾的最大共同子序列长度
    int max_len;
    int minDistance(string word1, string word2) {
        //注意！！！为了方便初始化，在0的位置加上一个空格
        word1=' '+word1;
        word2=' '+word2;
        for(int i=0;i<=word1.size();i++){
            for(int j=0;j<=word2.size();j++){
                //初始化dp边界
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else{
                    if(word1[i]==word2[j]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                max_len=max(max_len,dp[i][j]);
            }
        }
        return word1.size()+word2.size()-max_len*2;
    }
};
