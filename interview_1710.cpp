class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int major = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt == 0) {
                major = nums[i];
                cnt++;
            } else {
                if(major == nums[i]) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        if(cnt > 0)
        {
            int count = 0;
            for(int i = 0; i < nums.size(); i++) 
            {
                if(nums[i] == major) {
                    count++;
                }
            }
            if(count > nums.size()/2) {
                return major;
            }
        }
        return -1;
    }
};
