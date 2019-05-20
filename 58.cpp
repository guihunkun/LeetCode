class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        if(s.empty())
            return 0;
        int len = 0;
        int pos = s.size() - 1;
        while(pos >= 0 && s[pos] == ' ')
            pos--;
        while(pos >=0 && s[pos] != ' ')
        {
            len++;
            pos--;
        }
        return len;
    }
};

