class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        /*
        sort(nums.begin(), nums.end());
        return binary_search(nums.begin(), nums.end(), target);
        */
        if(nums.size() == 0)
            return false;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right- left) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[left] == nums[mid])
                left++;
            else if(nums[left] < nums[mid])
            {
                if(nums[left] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && target <= nums[right])
                    left = mid;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
