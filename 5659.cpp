class Solution 
{
public:
    int minimumLength(string s) 
    {
        int l = 0; 
        int r = s.size()-1;
        while(l < r)
        {
            if(s[l] == s[r]) {
                char c =s[r];
                while(l >= 0 && l <= r && s[l] == c) 
                    l++;
                while(r >= 0 && r >= l && s[r] == c) 
                    r--;
            } else {
                break;
            }
        }
        if(l > r) 
            return 0;
        if(l == r) 
            return 1;
        return  r-l+1;
    }
};

