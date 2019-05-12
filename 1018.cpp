
class Solution 
{
public:
    vector<bool> prefixesDivBy5(vector<int>& A) 
    {
        int num = 0; // long long num = 0;
        vector<bool> res(A.size(),false);
        for(int i = 0; i < A.size(); i++)
        {
            num = num << 1;
            num += A[i];
            num %= 5;
            if(num == 0)
                res[i] = true;
        }
        return res;        
    }
};

