class Solution 
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string,int> ParaSearch;
        string res = "", s = "";
        int repetCount = 0;
        //这里使用C++自带两个函数，isalpha()和tolower()函数
        //如果不是字母，就用空格隔开
        for (auto &c : paragraph) 
            c = isalpha(c) ? tolower(c) : ' ';
        //C++使用字符串的类 
        istringstream istring(paragraph);
        //将该字符串空格隔开的进行处理
        while( istring >> s)
         {
            //如果ban中不存在该字符串且map中对应的重复次数大于最大
            if(!ban.count(s) && ++ParaSearch[s] > repetCount)
            {
                repetCount = ParaSearch[s];
                res = s;
            }
        }
        return res;
    }
};
