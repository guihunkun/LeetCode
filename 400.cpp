#include"iostream"
#include"math.h"
using namespace std;
class Solution 
{
public:
    int findNthDigit(int n) 
    {
        int ans=0;
        int digits=1;
        long long numbers = 0, tempNums;    //numbers是累计的数字数目，tempNums是每一个循环所要加上的数字数目
        while (numbers < n)
        {
            tempNums=(long long)9*digits*(int)pow(10,digits-1);
            numbers+=tempNums;
            if(numbers>=n)
                break;
            digits++;
        }
        numbers -= tempNums;     //循环跳出时，当前数目要减去上一轮循环的数字数目才ok
        ans = (int)pow(10, digits - 1) - 1 + (int)(n - numbers)/digits;
        //这个answer是暂时的，不是最终结果；
        if((n-numbers)%digits==0)
            return ans%10;      //如果剩余数字的数目对digits可以整除，说明所求答案就是最后一个数字的末尾数
        return ((ans+1)/((int)pow(10,digits-(n-numbers)%digits)))%10;
                                //如果不可以整除，说明所求答案是下一个整数，根据余数可以知道是哪一位！！

    }
};
//https://blog.csdn.net/qq_28584889/article/details/84894950 
/*
下面以n = 56789为例，说明算法思想。
首先来一个循环，一位是数有9个，显然太少
2位数有180个，显然也太少
3位数有2700，还少
4位数有36000个，累计一下： 9+180+2700+36000 = 38889 还不够
5位数有5*90000= 450000；显然太多了！！！
所以，我们现在循环到4位数要截止，还剩下56789-38889=17900
也就是说还有17900个数字，我们前面四位数已经全部算完了，下面就只能上五位数了，从10000开始，17900/5=3580；
也就是说剩下的17900个数字刚好够3580个五位整数分；从10000开始，到13579结束。刚好够分的意思就是到最后一个整数的最末位结束，
那么结果就是13579的“9”了！！那么，如果有余数呢？比如还剩17901个数字，而不是17900；
那么17901够分3580个五位整数还余下一个数字；那这余下的一个数字就只能算到下一个整数了嘛。余数是多少，
就意味着下一整数的哪一位数字。OK，就是这样了。
*/
int main()
{
	int n=3;
	int ans=Solution().findNthDigit(n);
	cout<<ans<<endl;
	return 0;
}

