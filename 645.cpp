/*
class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> res(2,0);
        vector<int> rec(nums.size() + 1, 0);
        for(int n:nums)
        {
            rec[n]++;
        }
        for(int i = 1; i < rec.size(); i++)
        {
            if(rec[i] == 2)
                res[0] = i;
            if(rec[i] == 0)
                res[1] = i;
        }
        return res;
    }
};
*/
class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int rep, miss;
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            if(nums[i] != i + 1 && nums[i] == nums[nums[i] - 1])
            {
                rep = nums[i];
                miss = i + 1;
            }
        }
        return {rep, miss};
    }
};
