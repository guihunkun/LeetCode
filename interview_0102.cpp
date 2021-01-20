/*
//    Method 1
class Solution 
{
public:
    bool CheckPermutation(string s1, string s2) 
    {
        if(s1.size() != s2.size()) {
            return false;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
*/

// Method 2
class Solution 
{
public:
    bool CheckPermutation(string s1, string s2) 
    {
        if(s1.size() != s2.size()) {
            return false;
        }
        unordered_map<char, int> rec;
        for(int i = 0; i < s1.size(); i++)
        {
            rec[s1[i]]++;
        }
        for(int i = 0; i < s2.size(); i++)
        {
            rec[s2[i]]--;
            if(rec[s2[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};
