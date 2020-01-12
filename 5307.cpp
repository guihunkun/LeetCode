class Solution 
{
public:
    bool isNozeroNum(int n)
    {
        while(n != 0)
        {
            int a = n%10;
            n/=10;
            if(a == 0)
                return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> res(2,0);
        for(int i = 1; i < n; i++)
        {
            if(isNozeroNum(i) && isNozeroNum(n-i))
            {
                res[0] = i;
                res[1] = n-i;
            }
        }
        return res;
    }
};
