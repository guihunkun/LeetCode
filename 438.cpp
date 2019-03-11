#include"iostream"
#include"vector"
#include"string"
using namespace std;
/*
    bool helper(string s,string p,int k)
    {
        int np=p.size();
        int ns=s.size();
        vector<int> rel(26,0);
        for(int i=0;i<np;i++)
        {
            rel[(int)(p[i]-'a')]++;
            if(k<ns)
                rel[(int)(s[k++]-'a')]--;
        }
        for(int i=0;i<26;i++)
            if(rel[i]!=0)
                return false;
        return true;
        
    }
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> res;
        int sl=s.size();
        int pl=p.size();
        if(sl<pl)
            return res;
        for(int i=0;i<s.size();i++)
            if(helper(s,p,i))
                res.push_back(i);
        return res;
    }
*/
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> pv(26,0), sv(26,0), res;
        if(s.size() < p.size())
           return res;
        // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);
        int i=1;
        int j=i+p.size()-1;
        for(int i=p.size();i<s.size();i++)
        {
            ++sv[s[i]-'a'];
            --sv[s[i-p.size()]-'a']; 
            if(pv == sv)  
               res.push_back(i-p.size()+1);
        }
        return res;
    }
int main()
{
	string s="abab";
	string p="ab";
	vector<int> gh;
	gh=findAnagrams(s,p);
	for(int i=0;i<gh.size();i++)
		cout<<gh[i]<<" ";
	return 0; 
}
