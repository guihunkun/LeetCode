class Solution 
{
public:
    bool isLongPressedName(string name, string typed) 
    {
        int j = 0;
        for(int i = 0; i < typed.size(); i++)
        {
            if(j < name.size() && name[j] == typed[i])
                j++;
            else if(i == 0 || typed[i - 1] != typed[i])
                return false;
        }
        return j == name.size();
            
    }
};
