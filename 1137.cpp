class Solution 
{
public:
    int tribonacci(int n) 
    {
        int res1 = 0;
        int res2 = 1;
        int res3 = 1;
        int res = 0;
        if(n == 0) {
            return res1;
        }
        if(n <= 2) {
            return res2;
        }
        while(n > 2) {
            res = res1 + res2 + res3;
            res1 = res2;
            res2 = res3;
            res3 = res;
            n--;
        }
        return res;
    }
    
    
    /*
    int tribonacci(int n) 
    {
        int res1 = 0;
        int res2 = 1;
        if(n == 0)
            return res1;
        if(n <= 2)
            return res2;
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
    */
};
