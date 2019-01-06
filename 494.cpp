/*
����ԭ����ΪS��Ŀ��ֵΪtarget����ôԭ�����Ȼ���Էֳ��������֣�һ�����������Ԫ��ǰ����Ҫ��-���������ʱ��Ӧ������������
��һ�����������Ԫ��ǰ����Ҫ��+���������ʱ��Ӧ�������ӷ������ǽ����ӷ����ֵ������ΪP�����������ֵ������ΪN���ٸ����ӣ�
����S = {1��2��3��4��5}��target = 3����ô��һ�ֿ�����1-2+3-4+5����P = {1��3��5}��N = {2��4}��
�������ǿ���֪����target = sum(P) - sum(N)��
��ôsum(P) + sum(N) + sum(P) - sum(N) = sum(S) + target = 2sum(P)��
��ôsum(P) = [target + sum(S)] / 2��
�������ϵ��Ƶ������ǿ��Եõ������Ľ��ۣ�
������Ҫ�ҵ�����һ��������P��ʹ��������֮�͵���ԭ����֮����Ŀ��ֵ�ĺ͵�һ�룬������Ҫ�ҵ����������е���Ŀ��
�Զ��׼������ԭ����֮����Ŀ��ֵ�ĺ�Ϊ�������϶������������������У����ԭ����֮��С��Ŀ��ֵ��
Ҳ�϶������ڣ���Ϊ��������£���ʹ������Ķ���+��������Ԫ����Ӷ�С��Ŀ��ֵ���϶����������������Ľ����������
�ų������ϵ������������֮�����ǽ������о��ľ�����ԭ�������ҵ�֮�ͷ��������������и������ǳ�����DP�ķ�����

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) 
            sum += nums[i];
        if (sum < S || (sum + S) % 2 != 0) 
            return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target+1,0);
        dp[0] = 1;   //dp[i]��ָ��Ϊi�ļ����ж��ٸ�
        for (int i = 0; i < nums.size(); i++) 
            for (int j = target; j >= nums[i]; j--) 
                dp[j] += dp[j - nums[i]];
        return dp[target];
    }
};
