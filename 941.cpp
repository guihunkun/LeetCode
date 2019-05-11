class Solution 
{
public:
    bool validMountainArray(vector<int>& A) 
    {
        if(A.size() < 3)
            return false;
        int i = 1;
        if(A[1] <= A[0])
            return false;
        for(; i < A.size()-1; i++)
        {
            if(A[i] <= A[i-1])
                break;
        }
        if(A[A.size()-2] <= A[A.size()-1])
            return false;
        for(; i < A.size()-1; i++)
            if(A[i] <= A[i+1])
                return false;
        return true;
    }
};
