class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        int n = words.size();
        int res = 0;
        vector<int> bits(n, 0);
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < words[i]. size(); j++)
            {
                bits[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(bits[i] & bits[j])
                    continue;
                else
                    res = max(res, (int)(words[i].size()*words[j].size()));  
            }
        }
        return res;
    }
};
