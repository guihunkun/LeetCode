class Solution 
{
public:
    bool checkPerfectNumber(int num) 
    {
        if(num <= 0)
            return false;
        int sum = 1, high = sqrt(num);
        for(int i = 2; i<= high; i++)
            if(num % i == 0)
                sum += (i + num / i);
        if(high * high == num)
            sum -= high;
        return sum == num;
                
    }
};

