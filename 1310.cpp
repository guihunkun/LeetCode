class Solution 
{
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        int n = arr.size();
        vector<int> pre_xor(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pre_xor[i] = arr[i-1] ^ pre_xor[i-1];
        }
        vector<int> ans;
        for(auto &query : queries) {
            int L = query[0], R = query[1];
            ans.push_back(pre_xor[R+1] ^ pre_xor[L]);
        }
        return ans;
    }
};
