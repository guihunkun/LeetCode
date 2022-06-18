class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int left = 0, right = 0;
        int res = 0, numOfZero = 0;
        for(; right < nums.size(); right++)
        {
            if(nums[right] == 0) {
                numOfZero++;
            }
            while(numOfZero > 1)
            {
                if(nums[left] == 0) {
                    numOfZero--;
                }
                left++;
            }
            res = max(res, right-left);
        }
        return res;
    }
};

