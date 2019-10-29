class Solution 
{
public:
    string reverseWords(string s) 
    {
        for(int i = 0; i < s.size(); i++)
        {
            while(s[i] == ' ')
            {
                i++;
            }
            int left = i, right = i;
            while(right <s.size() && s[right] != ' ')
            {
                right++;
            }
            for(int j = left; j < (right +left)/2; j++)
            {
                swap(s[j], s[right - 1 - j + left]);
            }
            i = right;
        }
        return s;
    }
};


