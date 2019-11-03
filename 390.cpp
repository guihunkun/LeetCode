/*
class Solution 
{
public:
    int lastRemaining(int n) 
    {
        int head = 1, step = 1;
        bool direction = true; //ture  for ->, f for <-;
        while(n > 1)
        {
            if(direction)
                head += step;
            else
                head += n%2 == 0 ? 0 : step;
            step *= 2;
            n/=2;
            direction =! direction;
        }
        return head;   
    }
};
*/
class Solution 
{
public:
    int lastRemaining(int n) 
    {
        if(n == 1)
            return 1;
        return 2*(n/2 + 1 - lastRemaining(n/2));
    }
};
