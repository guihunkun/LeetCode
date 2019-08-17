class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res(2, -1);
        if(nums.size() == 0)
            return res;
        //find front
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] >= target)
                end = mid;
            else
                start = mid;
        }
        if(nums[start] == target)
            res[0] = start;
        else if(nums[end] == target)
            res[0] = end;
        
        //find back
        start = 0; end = nums.size() - 1;
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] <= target)
                start = mid;
            else
                end = mid;
        }
        if(nums[end] == target)
            res[1] = end;
        else if(nums[start] == target)
            res[1] = start;
        
        return res;
    }
};
