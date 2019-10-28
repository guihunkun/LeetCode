/*
class Solution 
{
public:
    bool isPowerOfFour(int num) 
    {
        if (num <= 0) 
            return false;
        return  ((num&(num-1))==0 && ((num&0x55555555)));
    }
};
*/
class Solution 
{
public:
    bool isPowerOfFour(int num) 
    {
        if(num <= 0) 
            return false;
        if(num == 1)
            return true;
        while(num > 1)
        {
            if(num%4 != 0)
                return false;
            num/=4;
        }
        return true;
    }
};
