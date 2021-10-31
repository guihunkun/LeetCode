#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
#include"string" 
#include"set"
using namespace std;

    bool isAnagram(string s, string t) 
    {
        vector<int> count(26, 0);
        for(int i = 0; i < s.size(); i ++)
            count[s[i]-'a'] ++;
        for(int i = 0; i < t.size(); i ++)
            count[t[i]-'a'] --;
        for(int i = 0; i < 26; i ++) {
            if(count[i] != 0) {
                return false;
	    }
	}
        return true;
    }

int main()
{
	string s="an";
	string t="na";
	bool bo=isAnagram(s,t);
	cout<<bo<<endl;
	return 0;
}


