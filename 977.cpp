/*
class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        for(int i = 0; i < A.size(); i++)
            A[i] = abs(A[i]);
        sort(A.begin(),A.end());
        for(int i = 0; i < A.size(); i++)
            A[i] = A[i] * A[i];
        return A;
    }
};
*/
class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        vector<int> res(A.size());
        int neg = 0;
        while(neg < A.size() && A[neg] < 0)
        {
            A[neg] = A[neg] * A[neg];
            neg ++;
        }
        int pos = neg;
        while(pos < A.size())
        {
            A[pos] = A[pos] * A[pos];
            pos ++;
        }
        
        pos = neg;
        neg = neg - 1;
        int r = 0;
        while(pos < A.size() && neg >= 0)
        {
            if(A[pos] <= A[neg])
                res[r++] = A[pos++];
            else
                res[r++] = A[neg--];    
        }
        while(pos < A.size())
            res[r++] = A[pos++];
        while(neg >= 0)
            res[r++] = A[neg--];
        return res;        
    }
};
