class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int res = 0, i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(i < j) 
        {
            res += nums[j--] - nums[i++];
        }
        return res;
    }
};
