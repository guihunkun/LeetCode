class Solution 
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        int a,b;
        if(x == 1)
            a = 1;
        else
            a = log(bound)/log(x);
        if(y == 1)
            b = 1;
        else 
            b = log(bound)/log(y);
        int num;
        vector<int> res;
        set<int> rec;
        for(int i = 0; i <= a && pow(x,i) <= bound; i++)
        {
            for(int j = 0; j <= b && pow(y,j) <= bound; j++)
            {
                num = pow(x,i) + pow(y,j);
                if(num <= bound)
                    rec.insert(num);
            }
        }
        res.clear();
        res.insert(res.end(),rec.begin(), rec.end());
        return res;
    }
};
