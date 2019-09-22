class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();)
        {
            if(nums[i]==nums[i-1])
                i+=2;
            else
                return nums[i-1];
        }
        return nums[nums.size()-1];
        
    }
};


class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(((mid%2) && (nums[mid] == nums[mid - 1]))||(((mid%2) == 0) &&(nums[mid] == nums[mid + 1])))
                left = mid + 1;
            else
                right = mid;
        }
        return nums[right];
    }
};
