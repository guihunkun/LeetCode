class Solution 
{
    static const vector<int> fac;
public:
    string getPermutation(int n, int k) 
    {
        string res;
        string s = string("123456789").substr(0, n);
        --k;
        while(k > 0)
        {
            size_t i = k/fac[n - 1];
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac[n - 1];
            --n;
        }
        return res + s;
    }
};
const vector<int> Solution::fac = {0,1,2,6,24,120,720,5040,40320,362880,3628800};

