/*
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        return (nums[n]-1)*(nums[n-1]-1);
    }
};
*/
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxNum = max(nums[0], nums[1]), secNum = min(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] > secNum)
            {
                int temp = maxNum;
                if(nums[i] >= maxNum)
                {
                    maxNum = nums[i];
                    secNum = temp;
                }
                else
                {
                    secNum = nums[i];
                }
            }
        }
        return (maxNum-1)*(secNum-1);
    }
};
