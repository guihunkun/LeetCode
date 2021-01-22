class Solution 
{
public:
    bool isUnique(string astr) 
    {
        set<char> rec;
        for(int i = 0; i < astr.size(); i++)
        {
            if(rec.count(astr[i]) > 0) {
                return false;
            }
            rec.insert(astr[i]);
        }
        return true;
    }
};
