/*
class Solution 
{
public:
    int lenLongestFibSubseq(vector<int>& A) 
    {
        int N = A.size();
        unordered_set<int> rec(A.begin(), A.end());
        int res = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i+1; j < N; j++)
            {
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while(rec.find(y) != rec.end())
                {
                    int z = x+y;
                    x = y;
                    y = z;
                    res = max(res, ++length);
                }
            }
        }
        return res >= 3 ? res : 0;
    }
};
*/

class Solution 
{
public:
    int lenLongestFibSubseq(vector<int>& A) 
    {
        int N = A.size();
        unordered_map<int, int> index;
        for (int i = 0; i < N; ++i)
            index[A[i]] = i;

        unordered_map<int, int> longest;
        int ans = 0;
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < k; ++j) {
                if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                    int i = index[A[k] - A[j]];
                    longest[j * N + k] = longest[i * N + j] + 1;
                    ans = max(ans, longest[j * N + k] + 2);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};
