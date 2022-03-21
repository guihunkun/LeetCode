class Solution 
{
public:
    bool helper(long long a,long long b,string num) 
    {
        if (num.size()==0)
            return true;
        long long c = a+b;
        string cc = to_string(c);
        int k=0;
        while (k<cc.size()) 
        {
            if (num[k]!=cc[k])
                return false;
            k++;
        }
        return helper(b,c,num.substr(k));
    }
    
    long long get_num(string num,int st,int ed) 
    {
        long long res=0;
        for (int i=st;i<=ed;++i) 
        {
            int cc = num[i]-'0';
            res = res*10+cc;
        }
        return res;
    }
    
    bool isAdditiveNumber(string num) 
    {
        int n=num.size();
        for (int i=1;i<=(n-1)/2;++i) 
        {
            if (num[0]=='0' && i>=2)
                break;
            for (int j=i+1;j-i<=n-j && i<=n-j;j++) 
            {
                if (num[i]=='0' && j-i>=2)
                    break;
                long long a = get_num(num,0,i-1);
                long long b = get_num(num,i,j-1);
                if (helper(a,b,num.substr(j)))
                    return true;
            }
        }
        return false;
    }
};


