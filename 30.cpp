class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        if(words.size()<1 || s.size()<1 || s.size() < words[0].size()*words.size())             return res;
        int wordLen = words[0].size(), lens = wordLen*words.size();
        int target = 0, cur = 0;
        unordered_map<string,int> allWord;
        for(auto& it:words)
        {
            allWord[it]++;
            for(auto& i:it) 
                target += i;
        }
        for(int i=0; i<lens; i++) 
            cur += s[i];
        // 先看当前字符串的 ASCII 码相加是否相等 方便去重
        for(int i=0, j; i<=s.size()-lens; cur -= s[i], cur += s[lens + i++])
        {
            // 快速去重
            if(cur != target) continue;
            // 确认一下，是否为真的匹配
            unordered_map<string,int> tem(allWord);
            for(j=i; j<i+lens; j+=wordLen)
                if(tem[s.substr(j, wordLen)]-- == 0) 
                    break;
            if(j == i+lens) 
                res.push_back(i);
        }
        return res;
    }
};
