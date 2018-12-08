#include"iostream"
#include"math.h"
#include"limits.h"
using namespace std;
int main()
{
        int result[2],nums[3];
        nums[0]=3;nums[1]=2;nums[2]=4;
        int target=6;
        int s[3];
        int k=0,t=0;
        for(int i=0;i<3;i++)
            s[i]=target-nums[i];
        for(k=0;k<3;k++)
            for(t=k+1;t<3;t++)
            {
                if(s[t]==nums[k])
                {
                	int n=k>t?k:t;
                	int m=k>t?t:k;
                    result[0]=m+1;
                    result[1]=n+1;
                }
            }
        cout<<result[0]<<result[1]<<endl;
    return 0;
}
