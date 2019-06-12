class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low = nums[0];
        int fast = nums[0];
        do
        {
            low = nums[low];
            fast = nums[nums[fast]];
        }while(low != fast);
        int part1 = nums[0];
        int part2 = low;
        while(part1 != part2)
        {
            part1 = nums[part1];
            part2 = nums[part2];
        }
        return part1;
    }
};
