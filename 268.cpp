/*
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int sumnums=0;
        for(int i = 0; i < nums.size(); i++)
            sumnums+=nums[i];
        return nums.size()*(nums.size()+1)/2-sumnums;
    }
};
*/

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == i)
                continue;
            else if(nums[i] != i && nums[i]<nums.size())
            {
                swap(nums[i],nums[nums[i]]);
                i--;
            }
            else
                continue;
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i)
                return i;
        return nums.size();
    }
};


