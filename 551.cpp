class Solution 
{
public:
    bool checkRecord(string s) 
    {
        if(s.size() == 0)
        {
            return true;
        }
        unsigned int a = 0;
        for(int i = 0; i < s.size() && a < 2; i++)
        {
            if(s[i] == 'A')
            {
                a++;
            }
            if(i <= s.size()-3 && s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L')
            {
                return false;
            }
        }
        return a < 2;

    }
};
