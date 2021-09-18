class Solution 
{
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
        vector<int> res;
        vector<int>::iterator it;
        for(int i = 0; i < index.size(); ++i)
        {
            it = res.begin() + index[i];
            res.insert(it, nums[i]);
        }
        return res;
    }
};
