class Solution 
{
public:
    int min3(int a, int b, int c)
    {
        return min(a, min(b,c));
    }
        
    int nthUglyNumber(int n)
    {
        vector<int> res(n);
        res[0] = 1;
        int ind1 = 0, ind2 = 0, ind3 = 0;
        int k = 1;
        while(k < n)
        {
            int num = min3(res[ind1] * 2, res[ind2] * 3, res[ind3] * 5);
            if(res[ind1] * 2 == num)
                ind1 ++;
            if(res[ind2] * 3 == num)
                ind2 ++;
            if(res[ind3] * 5 == num)
                ind3 ++;
            res[k] = num;
            k++;
        }
        return res[n - 1];    
    }
};


