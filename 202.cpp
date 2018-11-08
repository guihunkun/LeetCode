#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
#include"set"
using namespace std;

    int Happy(int t)
    {
        int su=0;
        do
        {
            su+=pow((t%10),2);
            
        }while(t/=10);
        //cout<<su<<endl;
        return su;
    }
    bool isHappy(int n)
    {
        set<int> record;
        int mu=Happy(n);
        while(mu!=1)
        {
            

            record.insert(mu);
			mu=Happy(mu);
            if(record.find(mu)!=record.end())
                return false;
            if(mu==1)
                break;            
        }
        return true;
        
    }
int main()
{
	int  n=19;
	Happy(n);
	bool bo=isHappy(n);
	cout<<bo<<endl;
	return 0;
}
