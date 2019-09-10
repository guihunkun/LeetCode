class Solution 
{
public:
    bool isVowels(char c)
    {
        string  Vowels = "aeiouAEIOU";
        for(int i = 0; i < Vowels.size(); ++i)
        {
            if(c == Vowels[i]) return true;
        }
        return false;
    }
    string reverseVowels(string s) 
    {
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(!isVowels(s[i])) 
                ++i;
            if(!isVowels(s[j])) 
                --j;
            if(isVowels(s[i]) && isVowels(s[j]))
            {
                swap(s[i],s[j]);
                ++i,--j;
            }
        }
        return s;
    }
};
