/*
class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int ret = 0;
        for(int i = 31; i >= 0; --i)
        {
            int c = (1<<i);
            if((m&c) == (n&c))
            {
                ret |= (m&c);
            }
            else 
                break;
        }
        return ret;
    }
};
*/

class Solution 
{
/*
寻找m和n的32位二进制数中，前面的公共部分，然后后面的用0来补齐。
因为后面的位中，必然存在某一个数k，m<= k <= n，而k的32位二进制数在那个位置上是0，
做了位与运算之后，那一位就成0了。
*/
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int tmp = 0;
        while(m != n)
        {
            m = m >> 1;
            n = n >> 1;
            tmp++;
        }
        return m << tmp;
    }
};
