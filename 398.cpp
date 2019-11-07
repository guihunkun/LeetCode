class Solution 
{
public:
    vector<int>::iterator start, end;
    Solution(vector<int>& nums) 
    {
        start = nums.begin();
        end = nums.end();
    }
    
    int pick(int target) 
    {
        int res = -1;
        int count = 0;
        for (auto it = start; it != end; it++) 
        {
            if ((*it) == target) 
            {
                count++;
                if (rand() % count == 0)
                    res = it - start;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


