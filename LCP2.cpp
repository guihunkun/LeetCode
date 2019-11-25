class Solution 
{
public:
    vector<int> fraction(vector<int>& cont) 
    {
        int up = 1,down = cont[cont.size()-1];
        for(int i = cont.size()-2; i >= 0; --i)
        {
            up += cont[i] * down;
            swap(up,down);
        }    
        return {down,up};
    }
};
