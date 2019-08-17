class Solution 
{
public:
    void sort(vector<int>& nums, vector<int>& smaller, vector<int>& pos, int from, int to) 
    {
        if (from >= to) 
            return;
        int m = (from + to) / 2;
        sort(nums, smaller, pos, from, m);
        sort(nums, smaller, pos, m+1, to);
        vector<int> merged(to - from + 1);
        int i=from, j=m+1, k=0, jump = 0;
        while (i<=m || j<=to) 
        {
            if (i>m) 
            {
                //jump ++;
                merged[k++] = pos[j++];
            } 
            else if (j>to) 
            {
                smaller[pos[i]] += jump;
                merged[k++] = pos[i++];
            } 
            else if (nums[pos[i]] <= nums[pos[j]]) 
            {
                smaller[pos[i]] += jump;
                merged[k++] = pos[i++];
            } 
            else 
            {
                jump ++;
                merged[k++] = pos[j++];
            }
        }
        for(int p=0; p<merged.size(); p++) 
            pos[from+p] = merged[p];
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int> smaller(nums.size()), pos(nums.size());
        for(int i=0; i<pos.size(); i++) 
            pos[i] = i;
        sort(nums, smaller, pos, 0, nums.size()-1);
        vector<int> result(nums.size());
        for(int i=0; i<nums.size(); i++) 
            result[i] = smaller[i];
        return result;
    }
};
