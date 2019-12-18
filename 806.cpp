class Solution 
{
public:
    vector<int> numberOfLines(vector<int>& widths, string S) 
    {
        int lines = 1, width = 0;
        for(char c : S)
        {
            int w = widths[c-'a'];
            width += w;
            if(width > 100)
            {
                lines++;
                width = w;
            }
        }
        vector<int> res(2);
        res[0] = lines;
        res[1] = width;
        return res;
    }
};
