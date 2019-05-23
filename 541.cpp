class Solution 
{
public:
    string reverseStr(string s, int k)
    {
        int i=0;
        while(i < s.size())
        {
            if(i+k <= s.size())
                reverse(s.begin()+i, s.begin()+i+k);
            else 
                reverse(s.begin()+i,s.end());            
            i+=2*k;
        }
        return s;
    }
};
