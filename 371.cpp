class Solution 
{
public:
    int getSum(int a, int b) 
    {
        int sum = 0;
        int c = 0;  // carry
        for(int i = 0; i < 32 ; ++i) 
        {
            int bits = ((a >> i) & 0x1) + ((b >> i) & 0x1) + c; // counts bits for the index
            c = (bits > 1)?1:0;          // Set the carry
            sum |= (bits % 2 << i);      // Set the bit for the index
        }
        return sum;
    }
};
