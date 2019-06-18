class Solution 
{
public:
    bool circularArrayLoop(vector<int>& nums) 
    {
        if(nums.size() < 2) 
            return false;
        int slow, fast;
        int N = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            slow = i;
            fast = nextpos(nums, slow);
            while(nums[fast] * nums[i] > 0 && nums[nextpos(nums, fast)] * nums[i] > 0)
            {
                if(fast == slow)
                {
                    if(slow == nextpos(nums, slow))
                        break;
                    return true;
                }
                fast = nextpos(nums, nextpos(nums, fast));
                slow = nextpos(nums, slow);
            }
        }
        return false;
    }
    int nextpos(vector<int>& nums, int index)
    {
        int N = nums.size();
        int next = index + nums[index];
        return next >= 0 ? (next % N) : (next % N + N);
    }
};
