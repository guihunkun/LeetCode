class Solution 
{
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int, int> nc, tail;
        for(auto num : nums)
        {
            nc[num]++;
        }
        
        for(auto num : nums)
        {
            if(nc[num] == 0) 
                continue;
            else if(nc[num] > 0 && tail[num-1] > 0)
            {
                nc[num]--;
                tail[num-1]--;
                tail[num]++;
            }
            else if(nc[num] > 0 && nc[num+1] > 0 && nc[num+2] > 0)
            {
                nc[num]--;
                nc[num+1]--;
                nc[num+2]--;
                tail[num+2]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
