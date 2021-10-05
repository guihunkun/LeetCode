class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string res;
        char tmp;
        while(n)
        {
            n --;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
    }
};


