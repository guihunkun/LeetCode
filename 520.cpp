
class Solution 
{
public:
    bool caps(char w)
    {
        if(w >= 'a' && w <= 'z')
            return false;
        else
            return true;
    }
    bool detectCapitalUse(string word) 
    {
        int l = word.length();
        if(l <= 1)
            return true;
            
        bool second = caps(word[1]);
        
        for(int i = 2; i < l;i++)
            if(second != caps(word[i]))
                return false;
        
        if(second)
            return caps(word[0]);
        return true;
    }
};

