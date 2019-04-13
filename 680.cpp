class Solution 
{
public:
    bool isPalindrome(string s,int i,int j)
    {
        for(int k=i;k<=i+(j-i)/2;k++)
        {
            if(s[k]!=s[j-k+i])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                int j=s.size()-1-i;
                return (isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1));
            }
        }
        return true;
    }
};
