
class Solution 
{
public:
    int fib(int N) 
    {
        long long first = 0, second = 1;
        long long fibN = 0;
        if(N == 0)
            return 0;
        if(N == 1)
            return 1;
        for(int i = 2; i <= N; i++)
        {
            fibN = first + second;
            first = second ;
            second = fibN;
        }
        return fibN;
    }
}; // O(n)

/*
class Solution 
{
public:
    int fib(int N) 
    {
        if(N <= 0)
            return 0;
        if(N == 1)
            return 1;
        return fib(N - 1) +fib(N - 2);
    }
}; // O(2^n)
*/

