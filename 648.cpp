/*
class Solution 
{
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        set<string> s;
        for(auto& a:dict)
            s.insert(a);
        stringstream ss(sentence);
        string ret;
        string init;
        if(sentence.empty())
            return ret;
        while(ss>>init)
        {
            for(int i = 0; i<init.size(); i++)
            {
                if(s.find(init.substr(0,i))!=s.end())
                {
                    init = init.substr(0,i);
                }
            }
            ret = ret+init+' ';
        }
        ret.erase(ret.end()-1);
        return ret;
    }
};
*/
class Solution 
{
public:
    static bool cmp(const string& s1, const string& s2)
    {
        return s1.size() < s2.size();
    }

    string replaceWords(vector<string>& dict, string sentence)
     {
        sort(dict.begin(), dict.end());
        istringstream line(sentence);
        string word,result="";
        while(line>>word)
        {
            int i=0;
            for(;i<dict.size();++i)
            {
                //找到前缀词，将前缀词加到result中
                if(dict[i][0]==word[0]&&word.substr(0,dict[i].size())==dict[i])                      {
                    result+=dict[i]+" ";
                    break;
                }
            }
            //没有找到前缀词，将原有的单词添加到result中
            if(i==dict.size())
                result+=word+" ";
        }
        if(result.size()>0)
            result.resize(result.size()-1);//删除最后一个空格
        return result;
    }
};
