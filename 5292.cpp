class Solution 
{
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        if(nums.size()%k != 0)
            return false;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> counter;
        for(int num : nums) 
        {
            counter[num]++;
        }
        for(int num : nums) 
        {
            if(counter[num] <= 0) 
            {
                continue;
            }
            for(int i = 0; i < k; i++) 
            {
                if(counter[num + i] <= 0) 
                {
                    return false;
                }
                counter[num + i]--;
            }
        }
        return true;  
    }
};
