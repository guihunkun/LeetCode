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
