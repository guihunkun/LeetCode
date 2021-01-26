class Solution 
{
public:
    bool oneEditAway(string first, string second) 
    {
        int len = first.size() - second.size();
        if(abs(len) > 1) {
            return false;
        }
        int left  = 0;
        while(left < first.size() && left < second.size() && first[left] == second[left]) {
            left++;
        }
        int fright = first.size()-1, sright = second.size()-1;
        while(fright >= 0 && sright >= 0 && first[fright] == second[sright]) {
            fright--;
            sright--;
        }
        return fright-left<1 && sright-left<1;
    }
};
