class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n=digits.size();
        digits[n-1]++;
        int i=n-1;
        while(digits[i]==10 && i>0)
        {
            digits[i]=0;
            digits[i-1]++;
            i--;
        }
        if(digits[0]==10)
        {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};

