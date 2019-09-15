class Solution 
{
public:
    string toHex(int num) 
    {
        string hexString = "";
        string hexChar = "0123456789abcdef";

        while (num) 
        {
            hexString = hexChar[num & 0xF] + hexString;
            num = (unsigned)num >> 4;
        }

        return hexString.empty() ? "0" : hexString;
    }
};
