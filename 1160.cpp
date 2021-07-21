
class Solution 
{
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int res = 0;
        map<char, int> rec;
        for(int i = 0; i < chars.size(); i++) {
            rec[chars[i]]++;
        }
        for(int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            map<char, int> word;
            for(int j = 0; j < s.size(); j++) {
                word[s[j]]++;
            }
            bool isHave = true;
            for(int j = 0; j < s.size(); j++) {
                if(word[s[j]] > rec[s[j]]) {
                    isHave = false;
                }
            }
            if(isHave) {
                res += s.size();
            }
        }
        return res;
    }
};

