/*
class Solution 
{
public:
    int binaryGap(int N) 
    {
        int res = 0;
        vector<int> rec;
        for(int i = 0; i < 32; ++i)
        {
            if(N&(1<<i))
            {
                rec.push_back(i);
            }
        }
        for(int i = 0; i < rec.size() - 1; ++i)
        {
            res = max(res, rec[i+1] - rec[i]);
        }
        return res;
    }
};
*/
class Solution 
{
public:
    int binaryGap(int N) 
    {
        int res = 0;
        int last = -1;
        for(int i = 0; i < 32; i ++)
        {
            if(N&(1<<i))
            {
                if(last >= 0)
                    res = max(res, i - last);
                last = i;
            }
        }
        return res;
    }
};
