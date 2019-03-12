#include"iostream"
#include"string"
using namespace std;
class Solution 
{
public:
    int titleToNumber(string s) 
    {
        long long res=0;
        if(s.size()==0)
            return res;
        for(int i=0;i<s.size();i++)
            res=res*26+(int)(s[i]-'A'+1);
        return res;
    }
};
int main()
{
	string s="AB";
	long long ans=Solution().titleToNumber(s);
	cout<<ans<<endl;
	return 0;	
}
