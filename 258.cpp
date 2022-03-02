#include"iostream"
using namespace std;
class Solution 
{
public:
    int Digits(int num)
    {
        int res = 0;
        while(num != 0)
        {
            int dig = (num % 10);
            res += dig;
            num = num/10;
            
        }
        return res;
    }
    int addDigits(int num) 
    {
		int res = 0;
        while(num >= 10)
        {
            
			res = Digits(num);
            num = res;
        }
        return num;
    }
};
int main()
{
	
	int num = 38;
	int res = Solution().addDigits(num);
	cout<<res<<endl;
	return 0;
} 


