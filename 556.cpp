/*
class Solution 
{
public:
    int nextGreaterElement(int n) 
    {
        string s=to_string(n);
        next_permutation(s.begin(),s.end());
        long long res=stoll(s);
        if(res>INT_MAX||res<=n)
        {
            return -1;
        }
        else
        {
            return  res; 
        }
        
    }
};
*/
class Solution 
{
public:
    int nextGreaterElement(int n) 
    {
        if(n < 10)
            return -1;
        string s=to_string(n);
        int len = s.size();
        int i,j;
        for(i = len - 1; i > 0; i--)
        {
            if(s[i-1] < s[i])
            {
                break;
            }
        }
        if(i == 0)
        {
            return -1; 
        }
        j = len - 1;
        while(j >= 0 && s[j] <= s[i-1])
        {
            j--;
        }
        swap(s[i - 1],s[j]);
        sort(s.begin() + i, s.end());
        long long res = stoll(s); //将字符串转换为long int
        if(res>(INT_MAX))
        {
            return -1;        
        }
        else
        {
            return res;       
        }
    }
};
