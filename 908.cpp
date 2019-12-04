class Solution 
{
public:
    int smallestRangeI(vector<int>& A, int K) 
    {
        int minNum = A[0], maxNum = A[0];
        for(auto x: A)
        {
            minNum = min(minNum, x);
            maxNum = max(maxNum, x);
        }
        return max(0, maxNum-minNum-2*K);
    }
};
