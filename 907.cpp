class Solution 
{
public:
    const long M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) 
    {
        int N = A.size();
        stack<int> st;
        vector<long> sums(N, 0);
        for(int i = 0; i < N; ++i) 
        {
            while(!st.empty() && A[st.top()] >= A[i]) 
            {
                st.pop();
            }
            if(st.empty()) 
            {
                sums[i] = A[i] * (i + 1);
            } 
            else 
            {
                sums[i] = sums[st.top()] + A[i] * (i - st.top());
            }
            sums[i] %= M;
            st.push(i);
        }
        long res = 0;
        for(auto x : sums) 
        {
            res += x;
            res %= M;
        }
        return res;
    }
};
