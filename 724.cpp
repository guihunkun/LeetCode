class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        if(nums.size() <= 2)
            return -1;
        int sum_left = nums[0], sum_right = 0;
        for(int i = 2; i < nums.size(); i++ )
            sum_right +=nums[i];
        if(sum_right + nums[1] == 0)  //�߽��������nums[1,nums.size()-1]==0ʱ��ȡpivot=0����ߵ���0���ұߵ���0��
            return 0; 
        for(int i = 1; i < nums.size()-1; i++)
        {
            if(sum_left == sum_right)
                return i;
            else
            {
                sum_left += nums[i];
                sum_right -= nums[i+1];
            }
        }
        
        //�߽��������nums[0,nums.size()-2]==0ʱ��ȡpivot=nums.size()-1����ߵ���0���ұߵ���0��
        sum_right = 0;
        for(int i = 2; i < nums.size(); i++ )
            sum_right +=nums[i];
        if(sum_right + nums[1] + nums[0] - nums[nums.size()-1] == 0)
            return nums.size()-1;
        return -1;
    }
};
