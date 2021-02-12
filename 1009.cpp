class Solution 
{
public:
    int bitwiseComplement(int N) 
    {
        int temp = 2;
        while(temp <= N)
        {    
            temp = temp << 1;
        }
        return temp - N - 1;  
    }
};
