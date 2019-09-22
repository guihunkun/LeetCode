class Solution 
{
public:
    string convertToBase7(int num) 
    {
        if(num == 0)
            return "0";
        string sign = (num>0)?"":"-";
        string res;
        num = abs(num);
        while(num > 0)
        {
            res = to_string(num%7) + res;
            num/=7;
        }
        res = sign + res;
        return res;
    }
};
