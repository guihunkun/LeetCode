/*
用up[i]和down[i]分别记录到第i个元素为止以上升沿和下降沿结束的最长“摆动”序列长度，遍历数组，如果nums[i]>nums[i-1]，表明第i-1到第i个元素是上升的，因此up[i]只需在down[i-1]的基础上加1即可，而down[i]保持down[i-1]不变；如果nums[i]<nums[i-1]，表明第i-1到第i个元素是下降的，因此down[i]只需在up[i-1]的基础上加1即可，而up[i]保持up[i-1]不变；如果nums[i]==nums[i-1]，则up[i]保持up[i-1]，down[i]保持down[i-1]。比较最终以上升沿和下降沿结束的最长“摆动”序列长度即可获取最终结果。具体代码：
*/

class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int sz = nums.size();
        if(!sz) return 0;
        vector<int> up(sz, 0), down(sz, 0);
        
        up[0] = down[0] = 1;
        for(int i=1; i<nums.size(); ++i) 
        {
            if(nums[i] > nums[i-1]) 
            {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1]) 
            {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else 
            {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        
        return max(up[sz-1], down[sz-1]);
    }
};

