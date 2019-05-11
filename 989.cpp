class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
        vector<int> res;
        int i = A.size();
        int num = K;
        while(--i >= 0 ||num > 0)
        {
            if(i >= 0)
                num += A[i];
            res.push_back(num % 10);
            num /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
