class Solution 
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        int res = 0;
        set<string> sons;
        map<string, int> hash;
        for(int len = minSize; len <= minSize; len++)
        {
            for(int i = 0; i < s.size() - len + 1; i ++)
            {
                string son = s.substr(i, len);
                if(getLetters(son) <= maxLetters) {
                    hash[son] ++;
                }
            }
        }
        auto it = hash.begin();
        while(it != hash.end()) {
            res = max(res, it->second);
            it ++;
        }
        return res;
    }
    int getLetters(string son)
    {
        int cnt = 0;
        set<char> hash;
        for(auto s:son)
        {
           hash.insert(s);
        }
        return hash.size();
    }
};
