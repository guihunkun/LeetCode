/*
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if(nums.size()<=0 || target<0)
            return 0;
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
            for(int j=0;j<nums.size();j++)
                if(i>=nums[j])
                    dp[i]+=dp[i-nums[j]];
        return dp[target];
        
    }
};
*/
/*
dp[i]��ʾĿ����Ϊi�Ľ�ĸ�����Ȼ�����Ǵ�1������target������ÿһ����i������nums���飬���i>=x, dp[i] += dp[i - x]�����Ҳ�ܺ���⣬����˵����[1,2,3] 4��������ӣ��������ڼ���dp[3]��ʱ��3���Բ��Ϊ1+x����x��Ϊdp[2]��3Ҳ���Բ��Ϊ2+x����ʱxΪdp[1]��3ͬ�����Բ�Ϊ3+x����ʱxΪdp[0]�����ǰ����е�����������������3����������ˣ�
*/
/*
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i < a) break;
                dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};
*/
/*
���targetԶ����nums����ĸ����Ļ���������㷨�������ʵ����Ż����ȸ�nums�����Ÿ���Ȼ���1������target������iС�������е�����xʱ������ֱ��break������Ϊ���������������ط�����.
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
