class Solution 
{
public:
    vector<int> countBits(int num) 
    {
        vector<int> res(num + 1);
        for(int i = 1; i <= num; i++)
            res[i] = res[i >> 1] + i % 2;
        return res;
    }
};
