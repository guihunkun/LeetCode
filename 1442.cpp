class Solution 
{
public:
    int countTriplets(vector<int>& arr) 
     {
        int size = arr.size();
        int dp[size];
        dp[0] = arr[0];
        //arr[0]^...^arr[i]，前i+1个值的异或结果（因为这里的i是下标）
        for(int i=1; i<size; i++) {
            dp[i] = dp[i-1]^arr[i];
        }
        int count = 0;
        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                for(int k=j; k<size; k++)
                {
                    //arr[i]^...^arr[j-1] compare to arr[j]^...^arr[k]
                    if( (dp[i]^dp[j-1]^arr[i]) == (dp[k]^dp[j]^arr[j])) count++;
                    //再异或回arr[i]和arr[j]，是因为在原来的结果中i和j所在的元素也被消掉了。
                }
            }
        }
        return count;
    }
};


