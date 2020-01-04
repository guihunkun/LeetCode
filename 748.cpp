class Solution 
{
public:
    void lowcase(string& s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
    }
    vector<int> count(string s)
    {
        vector<int> res(26, 0);
        for(char c : s)
        {
            if(c >= 'a' && c <= 'z')
                res[c-'a']++;
        } 
        return res;
    }
    bool isCompletingWord(vector<int> rec1, vector<int> rec2)
    {
        for(int i = 0; i < min(rec1.size(), rec2.size()); i++)
        {
            if(rec1[i] > rec2[i])
                return false;
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        string res = "";
        lowcase(licensePlate);
        vector<int> tar = count(licensePlate);
        for(int i = 0; i < words.size(); i++)
        {
            vector<int> wor = count(words[i]);
            if(isCompletingWord(tar, wor))
            {
                if(res.size() == 0 || res.size() > words[i].size())
                    res = words[i];
            }
        }
        return res;
    }
};
