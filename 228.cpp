class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int n = nums.size();
        vector<string> ans;

        int i = 0;
        while(i < n) 
        {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) 
                j++;

            if(i == j) 
                ans.push_back(to_string(nums[i]));
            else 
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));   
            i = j + 1;
        }
        return ans;
    }
};
