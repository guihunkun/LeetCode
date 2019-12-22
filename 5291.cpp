class Solution 
{
public:
    int count(int num)
    {
        int res = 0;
        while(num)
        {
            num /= 10;
            res++;
        }
        return res;
    }
    int findNumbers(vector<int>& nums) 
    {
        int res = 0;
        for(int num: nums)
        {
            if(count(num)%2 == 0)
                res++;
        }
        return res;
    }
};
