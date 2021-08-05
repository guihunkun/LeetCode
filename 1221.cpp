class Solution 
{
public:
    int balancedStringSplit(string s) 
    {
        int numR = 0, numL = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'L') {
                numL++;
            }
            if(s[i] == 'R') {
                numR++;
            }
            if(numL == numR && numL > 0) {
                res++;
                numL = 0;
                numR = 0;
            }
        }
        return res;
    }
};


