class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        set<long> record;
        long lt=t;
        for(int i=0;i<nums.size();i++)
        {
            set<long>::iterator it=record.lower_bound(nums[i]-lt);  
            if(it!=record.end() && (*it)-nums[i]<=lt) 
                return true;
            record.insert(nums[i]);            
            if(record.size()==k+1) 
                record.erase(nums[i-k]); 
        }
        return false;
    }
};

