class Solution 
{
public:
    bool isDividingNumber(int num)
    {
        vector<int> rec;
        int nu = num;
        int a;
        while(nu)
        {
            a = nu%10;
            if(a == 0)
                return false;
            else
                rec.push_back(a);
            nu /= 10;
        }
        for(int i = 0; i < rec.size(); i++)
        {
            if(num%rec[i] != 0)
                return false;
        }
        return true;

    }
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> res;
        for(int i = left; i <= right; i++)
        {
            if(isDividingNumber(i))
                res.push_back(i);
        }
        return res;
    }
};
