#include"iostream" 
#include"vector"
#include"algorithm"
#include"math.h"
using namespace std;
/*
    bool helper(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
    }
    int countPrimes(int n) 
    {
        int count=0;
        for(int i=2;i<n;i++)
            if(helper(i))
                count++;
        return count;
    }
*/

    int countPrimes(int n) 
    {
        vector<bool> memo(n+1,false);
        int count=0;
        for(int i=2;i<sqrt(n);i++)
            for(int j=2;i*j<n;j++)
                memo[i*j]=true;
        for(int i=2;i<n;i++)
            if(!memo[i])
                count++;
        return count;
    }
int main()
{
	int n=10;
	int res=0;
	res=countPrimes(n);
	cout<<res<<endl;
}
