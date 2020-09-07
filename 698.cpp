class Solution 
{
public:
    int n, len;
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        n=nums.size();
        vector<bool> vis(n, false);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) len += nums[i];
        if(len%k!=0) return false;
        len=len/k;
        return dfs(n-1, len, n, nums, vis);
    }
    
    //当前从id位置开始枚举,还有有个sz子集未合法是否能够使所有子集合法
    bool dfs(int id, int cur, int sz, vector<int>& arr, vector<bool>& vis) 
    {
        if(sz == 0) 
            return true; //n个数全部装下
        bool isok = false;
        for(int i=id; i>=0; i--) 
        {
            if(!vis[i] && cur>=arr[i]) { //当前的数能够装入当前子集中
                vis[i]=true;
                isok = cur^arr[i] ? dfs(i-1, cur-arr[i], sz-1, arr, vis) : dfs(n-1, len, sz-1, arr, vis);
                if(isok || !cur) return isok;
                vis[i] = false;
                while(i>0 && arr[i-1]==arr[i]) i--; //判重剪枝
            }
        }
        return isok;
    }
};
