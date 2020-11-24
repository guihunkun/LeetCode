class Solution 
{
public:
    int calculate(string s) 
    {
        int x = 1, y = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'A') {
                x = 2*x + y;
            } else if(s[i] == 'B') {
                y = 2*y + x;
            } else {
                continue;
            }
        }
        return x+y;
    }
};
