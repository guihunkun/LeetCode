class Solution 
{
public:
    int reachNumber(int target) 
    {
        target=abs(target);
        int i=1;
        while(i*(i+1)/2<target)
            i++;
        if(i*(i+1)/2==target)
            return i;
        else 
        {
            if((i*(i+1)/2-target)%2==0)
                return i;
            else
            {
                if(i%2==0)
                    return i+1;
                else
                    return i+2;
            }
        }
    }
};
