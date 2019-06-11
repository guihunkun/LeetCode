class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        assert(A.size() >= 3);
        int left = 0;
        int right = A.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(A[mid] < A[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
