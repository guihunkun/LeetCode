/*
class Solution 
{
public:
    void helper(vector<int>& nums, int k, vector<vector<int> >& v) 
    {
        if(k == nums.size()) 
            return;
        int n = v.size();
        for(int i = 0; i < n; ++i) 
        {
            if(v[i].back() <= nums[k]) 
            {
                auto u = v[i];
                u.push_back(nums[k]);
                v.push_back(u);
            }
        }
        v.push_back({nums[k]});
        helper(nums, k + 1, v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int> > v;
        helper(nums, 0, v);
        sort(v.begin(), v.end());
        vector<vector<int> > res;
        for(int i = 0; i < v.size(); ++i) 
        {
            if(v[i].size() < 2) 
                continue;
            if(i > 0 && v[i] == v[i - 1]) 
                continue;
            res.push_back(v[i]);
        }
        return res;
    }
};
*/

/*
class Solution 
{
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& path, int start) 
    {
        if(path.size() >= 2) 
            ans.push_back(path);
        if(start >= nums.size()) 
            return;
        unordered_set<int> s;
        // 如果set里已经记录了当前的值，则跳过；因为之前唤起的dfs里会把之后所有的同样的值都选中；
        // 只需要考虑从之后开始选中的重复的值即可
        for(int i = start; i < nums.size(); i++) 
        {
            if(s.find(nums[i]) != s.end()) 
                continue;
            if(path.size() == 0) 
            {
                s.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, path, i+1);
                path.pop_back();
            }
            else 
            {
                if(nums[i] >= path.back()) 
                {
                    s.insert(nums[i]);
                    path.push_back(nums[i]);
                    dfs(nums, path, i+1);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<int> path;
        dfs(nums, path, 0);
        return ans;
    }
};
*/
class Solution 
{
public:
    void dfs(vector<vector<int> >& res, vector<int>& sub, 
    vector<int>& nums, int index)
    {
        if(sub.size() >= 2)
        {
            res.push_back(sub);
        }
        unordered_set<int> hash;
        for(int i = index; i < nums.size(); i++)
        {
            if((sub.empty() || sub.back() <= nums[i]) && hash.find(nums[i]) == hash.end())
            {
                sub.push_back(nums[i]);
                dfs(res, sub, nums, i+1);
                sub.pop_back();
                hash.insert(nums[i]);
            }
        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int> > res;
        vector<int> sub;
        dfs(res, sub, nums, 0);
        return res;
    }
    
};
