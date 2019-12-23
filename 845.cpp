class Solution 
{
public:
    int longestMountain(vector<int>& A) 
    {
        int res = 0;
        int left = 0, right = -1;
        while(left < A.size())
        {
            right = left;
            if(right + 1 < A.size() && A[right] < A[right + 1])
            {
                while(right + 1 < A.size() && A[right] < A[right + 1])
                {
                    right++;
                }
                if(right + 1 < A.size() && A[right] > A[right + 1])
                {
                    while(right + 1 < A.size() && A[right] > A[right + 1])
                    {
                        right++;
                    }
                    res = max(res, right - left + 1);
                }
            }
            left = max(left + 1, right);
        }
        return res;
    }
};
