class Solution {
public:
    vector<string> split(string str)
    {
        vector<string> res;
        string tmp = "";
        for(int i=0;i<str.length();i++)
        {
            if(str[i] != ' ') 
            {
                if(i == str.length() - 1) 
                    res.push_back(tmp + str[i]);
                tmp += str[i];
            }
            else
            {
                res.push_back(tmp);
                tmp = "";
            }
        }
        return res;
    }
    bool wordPattern(string pattern, string str) 
    {
        vector<string> res = split(str);
        
        if(pattern.length() != res.size()) 
            return false;
        map<char, string> corre;
        map<char, string>::iterator it;
        set<string> word;
        set<string>::iterator itr;
        for(int i = 0; i < pattern.length(); i++)
        {
            it = corre.find(pattern[i]);
            if(it == corre.end())
            {
                itr = word.find(res[i]);
                if(itr != word.end()) 
					return false;
                corre.insert(pair<char, string>(pattern[i], res[i]));
                word.insert(res[i]);
            }
            else
            {
                if(it->second != res[i]) 
					return false;
            }
        }
        return true;
    }
};
