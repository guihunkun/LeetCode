class Solution 
{
public:
    int numJewelsInStones(string J, string S) 
    {
        set<char> rec;
        for(char c : J)
            rec.insert(c);
        int res = 0;
        for(char c : S)
        {
            if(rec.find(c) != rec.end())
                res++;
        }
        return res;
    }
};
