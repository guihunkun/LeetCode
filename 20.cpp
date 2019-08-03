class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> stc;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stc.push(s[i]);
            else
            {
                if(stc.size()==0)
                    return false;

                char c=stc.top();
                stc.pop();
                char mat;
                if(s[i]==')')
                    mat='(';
                else if(s[i]=='}')
                    mat='{';
                else
                    mat='[';
                if(mat!=c)
                    return false;

            }
        }
        if(stc.size()!=0)
            return false;
        return true;
    }
};
