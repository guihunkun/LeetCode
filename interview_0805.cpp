class Solution 
{
public:
    int multiply(int A, int B) 
    {
        if(A > B) 
            return multiply(B, A);
        if(A == 0) 
            return 0;
        return B + multiply(A - 1, B);
    }
};
