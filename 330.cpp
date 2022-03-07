/*
class Solution 
{
public:
    int minPatches(vector<int>& nums, int n) 
    {
        uint32_t m = 1, i = 0, p = 0, size = nums.size();
        while(m <= n) 
        {
            if(i < size && nums[i] <= m) m += nums[i++];
            else 
            {
                m += m;
                ++p;
            }
        }
        return p;
    }
};
*/
class Solution 
{
public:
    int minPatches(vector<int>& nums, int n) 
    {
        long N = nums.size();
        long i = 0,res = 0,bound = 1;
        while(bound<=n)
        {
            if (i < N && nums[i] <= bound)
            {
                bound += nums[i++];
            }
            else
            {
                bound += bound;
                res++;
            }
        }
        return res;        
    }
};
/*
定义整数bound，[0,bound)是现在能满足的区间，即[0,bound)内的数字都能被表示出来。数列中往后读一个数num，如果num<=bound，那么我们可以扩展区间为[0,bound+num)；如果num>bound，那么我们就需要添加一个数字来扩展区间，最有效的值显然为bound本身，区间扩展为[0,bound+bound)。定义bound初始值为1，循环读取数列中的数字并扩展区间，直到bound>n即可。
*/
