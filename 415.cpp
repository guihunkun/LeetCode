class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        string res="";
        int c=0;
        int i =num1.size()-1;
        int j = num2.size()-1;
        while(i>=0 || j>=0 || c>0)
        {
            if(i>=0)
                c+=num1[i]-'0';
            if(j>=0)
                c+=num2[j]-'0';
            char ch = c%10 +'0';
            res=ch+res;
            c/=10;
            i--;
            j--;
        }
        return res;
    }
};
