class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        vector<int> ans(mat[0]);
        for (int i = 1; i < mat.size(); ++i) {
            multiset<int> st;
            for (int x : ans) {
                for (int y : mat[i]) {
                    st.insert(x + y);
                }
            }
            ans.assign(st.begin(), st.end());
            ans.resize(min(k, (int)ans.size()));
        }
        return ans.back();
    }
};
