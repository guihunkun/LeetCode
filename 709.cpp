class Solution 
{
public:
    string toLowerCase(string str) 
    {
        string res = str;
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i] >= 'A' && res[i] <= 'Z')
                res[i] += 32;
        }
        return res;
    }
};
