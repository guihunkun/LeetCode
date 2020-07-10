class Solution 
{
public:
    vector<vector<int>> v;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        v.push_back({});
        for(int i = 0 ; i < nums.size() ; i++)
        {
            vector<vector<int>> b = v;
            for(int j = 0 ; j < b.size() ; j++)
            {
                vector<int> a = v[j];
                a.push_back(nums[i]);
                v.push_back(a);
            }
        }
        return v;
    }
};
