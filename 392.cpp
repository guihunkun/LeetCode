class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int is=0,it=0;
        while(is<s.size()&&it<t.size()){
            if(s[is]==t[it]){
                is++;
            }
            it++;
        }
        if(is==s.size()) 
            return true;
        else 
            return false;
    }
};
