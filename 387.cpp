class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        if(s.empty())
            return -1;
        if(s.size() == 1)
            return 0;
        vector<int> record(26);
        for(int i = 0; i < s.size(); i++)
        {
            if(record[s[i] - 'a'] == 0 && i < s.size() - 1 && s.find(s[i], i+1) == string::npos)
                return i;
            if(i == s.size() - 1 && record[s[s.size() - 1] - 'a'] == 0)
                return s.size() - 1;
            record[s[i] - 'a']++;
        }
        return -1;
    }
};
