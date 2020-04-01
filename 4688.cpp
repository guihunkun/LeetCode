class Solution 
{
public:
    bool validIPv4(string IP) 
    {
        if(IP.empty() || IP.back() == '.' || IP.front() == '.')
            return false;
        int digit = 0;
        int dot_ind = -1;
        int dot_num = 0;
        for(int i = 0; i < IP.size(); ++i) 
        {
            if(IP[i] == '.') 
            {
                if(i - dot_ind == 1)
                    return false;
                digit = 0;
                dot_ind = i;
                ++dot_num;
            } 
            else if(IP[i] >= '0' && IP[i] <= '9') 
            {
                if(i - dot_ind > 1 && digit == 0)
                    return false;
                digit = 10 * digit + IP[i] - '0';
                if(digit > 255)
                    return false;
            } 
            else 
            {
                return false;
            }
        }
        return dot_num == 3;
    }
    bool validHex(char c) 
    {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }
    bool validIPv6(string IP) 
    {
        if(IP.empty() || IP.back() == ':' || IP.front() == ':')
            return false;
        string elem;
        int colon_ind = -1;
        int colon_num = 0;
        for(int i = 0; i < IP.size(); ++i) 
        {
            if(IP[i] == ':') 
            {
                if(elem.empty())
                    return false;
                elem.clear();
                colon_ind = i;
                ++colon_num;
            } 
            else if(validHex(IP[i])) 
            {
                elem += IP[i];
                if (elem.size() > 4)
                    return false;
            } else {
                return false;
            }
        }
        return colon_num == 7;
    }
    string validIPAddress(string IP) 
    {
        if(validIPv4(IP))
            return "IPv4";
        if(validIPv6(IP))
            return "IPv6";
        return "Neither";
    }
};
