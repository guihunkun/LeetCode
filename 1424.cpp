class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        map<int, vector<int> > rec;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            for(int j = 0; j < nums[i].size(); j++) {
                rec[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        res.reserve(200100);
        for(auto& rec_iter : rec)
        {
            for(auto& num : rec_iter.second) {
                res.push_back(num);
            }
        }
        return res;
    }
};


