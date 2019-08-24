class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> record;
        for(int i=0;i<nums.size();i++)
        {
            if(record.find(nums[i])!=record.end())
                return true;
            record.insert(nums[i]);
            if(record.size()==k+1)
                record.erase(nums[i-k]);
        }
        return false;
    }
};
