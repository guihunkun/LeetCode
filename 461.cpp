class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int i = x ^ y;
        int count=0;
        
        while (i != 0) 
        {
            ++ count;
            i = (i-1)& i;
        }
/*  
如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减去1，那么原来处在整数最右边的1就会变成0，原来在1后面的所有的0都会变成1。其余的所有位将不受到影响。举个例子：一个二进制数1100，从右边数起的第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成1，而前面的1保持不变，因此得到结果是1011。
*/
        /*
        while(i)
        {
            if(i & 1)
                count++;
            i=i>>1;
        }
        */
        return count;
    }
};
