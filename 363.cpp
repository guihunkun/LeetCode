class Solution 
{
public:
    // n行数，m列数
    // O(m^2 * nlog(n)) 对所有可能的左右边界，在前缀和的基础上求小于k的最大连续子数组和
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size(), m = matrix[0].size();
        // 预处理前缀和
        vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 1; j <= m; j++) 
            {
                v[i][j] = v[i][j - 1] + matrix[i - 1][j - 1];
            }
        }

        // 两个for遍历所有可能的左右边界
        int res = INT_MIN;
        for(int l = 1; l <= m; l++) 
        {
            for(int r = l; r<= m; r++) 
            {
                // 存set，set查询lower_bound O(log(n))
                set<int> st;
                st.insert(0);
                int cur = 0;
                for(int i = 1; i <= n; i++) 
                {
                    // 第i-1行中l-r直接的数之和
                    int now = v[i][r] - v[i][l - 1];
                    cur += now;
                    // 对于当前的前缀和，找数中大于等于cur-k的最小元素
                    // 设找到的数为p，则p大于等于cur-k，必有 cur - p <= k
                    // 所有最小的p，使得cur-p的值最大，且该值小于等于k
                    auto it = st.lower_bound(cur - k);
                    if (it != st.end()) 
                        res = max(res, cur - *it);
                    st.insert(cur);
                }
            }
        }
        return res;
    }
};
