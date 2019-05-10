class Solution 
{
public:
    bool isMonotonic(vector<int>& A) 
    {
        return increasing(A) || decreasing(A);
    }
    bool increasing(vector<int>& A) 
    {
        for(int i = 0; i < A.size()-1; i++)
            if(A[i] > A[i+1])
                return false;
        return true;
    }
    bool decreasing(vector<int>& A) 
    {
        for(int i = 0; i < A.size()-1; i++)
            if(A[i] < A[i+1])
                return false;
        return true;
    }
};
