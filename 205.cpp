class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
            s = f(s);
            t = f(t);
            if(s == t) 
                return true;
            else 
                return false;
    }
    
    string f(string s) 
    {
        map<char, char> m;
        string ret;
        for(int i = 0 ; i < s.size() ; i ++) 
        {
            if(m.find(s[i]) == m.end()) 
            {
                if(m.empty()) 
                {
                    m[s[i]] = 'a';
                }
                else 
                {
                    m[s[i]] = m[s[i-1]] + 1;
                }
            }
            ret += m[s[i]];
        }
        return ret;
     }
    // 把字符串中第一个出现的字母映射为‘a’，第二个为‘b’，。。。，依次类推，最多为26个不同的字母。
    //映射完之后，两个字符串如果相同，即是同构字符串。
};

