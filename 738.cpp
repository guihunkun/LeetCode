class Solution 
{
public:
    int monotoneIncreasingDigits(int N) 
    {
        string strN = to_string(N);
        int i = 1;
        while (i < strN.length() && strN[i - 1] <= strN[i]) 
        {
            i += 1;
        }
        if(i < strN.length()) 
        {
            while(i > 0 && strN[i - 1] > strN[i]) 
            {
                strN[i - 1] -= 1;
                i -= 1;
            }
            for(i += 1; i < strN.length(); ++i) 
            {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};

