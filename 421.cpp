class Solution 
{
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int res = 0;
        int mark = 0;
        set<int> record;
        for(int i = 31; i >= 0; i--)
        {
            record.clear();
            mark |= (1<<i);// get the first n temporary variables
            for(int j = 0; j < nums.size(); j++)
                record.insert(nums[j] & mark);
            int tmp = res | (1<<i); 
            // Assume that the nth bit is 1, 
            //the first n-1 bit max is obtained from the previous iteration
            for (int pre : record) 
            {
                if (record.count(tmp ^ pre))
                {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};


