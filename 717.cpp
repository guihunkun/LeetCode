class Solution 
{
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int i = 0;
        for(; i < bits.size()-1; )
        {
            i += bits[i] + 1;            
        }
        return i == bits.size()-1;
    }
};
