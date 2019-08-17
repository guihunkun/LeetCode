class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size() == 0)
            return -1;
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end)
        {
            int mid = start +(end - start)/2;
            if(nums[end] < target)
            {
                if(nums[mid] >target || nums[mid] < nums[end])
                    end = mid;
                else if(nums[mid] == target)
                    return mid;
                else
                    start = mid;
            }
            else
            {
                if(nums[mid] > nums[end] || nums[mid] < target)
                    start = mid;
                else if(nums[mid] == target)
                    return mid;
                else
                    end = mid;
            }
        }
        if(nums[start] == target)
            return start;
        if(nums[end] == target)
            return end;
        return -1;
    }
};
