#include"iostream" 
#include<string>
using namespace std;
    bool isPalindrome(string s) 
    {
    	string str = "";
        int len = s.length();
        int lenStr = 0;
        for(int i = 0; i < len; i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                str += s[i];
                lenStr++;
            } 
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                str += (s[i] - 'A' + 'a');
                lenStr++;
            }
        }
        for(int i = 0; i < lenStr / 2; i++)
        {
            if(str[i] != str[lenStr - i - 1])
            {
                return false;
            }
        }
        return true;      
    }
int main()
{
	string s1="aabb aa";//"A man, a plan, a canal: Panama";
	bool po=isPalindrome(s1); 
	cout<<po<<endl;
	return 0;
}
