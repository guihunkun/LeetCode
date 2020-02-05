class Solution 
{
public:
    bool isNumber(string &s) 
    {
        // regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$");
        int i=s.find_first_not_of(' ');
        int d1=0, dot=0, d2=0, e=0, d3=0;
        if(s[i]=='+' || s[i]=='-') 
            ++i;
        for(; i<s.length() && isdigit(s[i]); d1=++i);
        if(i<s.length() && s[i]=='.') 
            dot=++i;
        for(; i<s.length() && isdigit(s[i]); d2=++i);
        if(dot && !d1 && !d2) 
            return false;
        if(i<s.length() && (d1||d2) && s[i]=='e') 
            e=++i;
        if(i<s.length() && e && (s[i]=='+'|s[i]=='-')) 
            ++i;
        for(; i<s.length() && isdigit(s[i]); d3=++i);
        if(e && (!(d1||d2) || !d3)) 
            return false;
        for(; i<s.length() && s[i]==' '; ++i);
        return i==s.length();
    }
};
