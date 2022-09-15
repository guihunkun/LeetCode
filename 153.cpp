class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        
        /*
        int start = 0, end = nums.size() - 1;
        int target = nums[nums.size() - 1];
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] > target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if(nums[start] < target)
        {
            return nums[start];
        }
        return nums[end];
        */
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
      if(nums[left] < nums[right]) 
	  	return nums[left];
      int mid = (left + right)/2;
      if(nums[left] <= nums[mid])
	  	left = mid + 1;
      else 
	  	right = mid;
	}
    return nums[left];
    }
};

/*
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] <= nums[end])
                end = mid;
            else
                start = mid;
        }
        if(nums[start] > nums[end])
            return nums[end];
        return nums[start];
    }
};
*/

