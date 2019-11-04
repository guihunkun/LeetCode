class Solution 
{
public:
    bool validUtf8(vector<int>& data) 
    {
        int count = 0;  
        for(const auto &val: data) 
        {  
            if(count == 0) 
            {                // check the bytes count
                if((val >> 5) == 0b110) 
                {
                    count = 1;
                }
                else if((val >> 4) == 0b1110) 
                {
                    count = 2;  
                }
                else if((val >> 3) == 0b11110) 
                { 
                    count = 3;
                }
                else if(val >> 7) 
                {	// the most significant bit cannot be 0
                    return false;
                } 
            } 
            else 
            {
                if((val >> 6) != 0b10) 
                {    // checking the leading bits in each byte
                    return false;  
                }
                --count;
            }
        }  
        return count == 0;        
    }
};
