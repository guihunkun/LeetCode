class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if(numerator == 0) 
            return "0";
        if(denominator == 0)
            return "-1";
        bool positive = (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0);
        long long nu = numerator;
        long long de = denominator;
        nu = abs(nu);
        de = abs(de);
        
        long long integer = nu / de;
        string decimal = "";
        map<long long, int> record;
        long long prev = nu % de;
        while (1) 
        {
            // no more remainder
            if (prev == 0) 
                break;
            prev *= 10;
            
            if (record.count(prev)) 
            {
                // found repeatition
                int p = record[prev];
                decimal = decimal.substr(0, p) + "(" + decimal.substr(p) + ")";
                break;
            }
            record[prev] = decimal.length();
            
            long long d = prev / de;
            decimal += ('0' + d);
            prev = prev % de;
        }
        string ret = std::to_string(integer);
        if (!positive) 
            ret = "-" + ret;
        if (decimal.length()) 
            ret += "." + decimal;
        return ret;
    }
};
