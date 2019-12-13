/*
class Solution 
{
public:
    string toGoatLatin(string S) 
    {
        unordered_set<char> vowels={'a','A','e','E','i','I','o','O','u','U'};
        istringstream ss(S);
        string temp,ans;
        string str="ma";
        while(ss>>temp)
        {    
            str+="a";
            if(vowels.find(temp[0])!=vowels.end())     //单词首字母是元音
                ans+=temp+str+" ";
            else 
                ans+=temp.substr(1)+temp[0]+str+" ";       //单词首字母不是元音
        }
        ans.pop_back();
        return ans;
    }
};
*/
class Solution 
{
public:
    /*
    vector<string> split(const string& s, char ch)
    {
        int start = 0;
        int len = 0;
        vector<string> ret;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ch)
            {
                ret.push_back(s.substr(start,len));
                start = i + 1;
                len = 0;
            }
            else
            {
                len++;
            }
        }
        if(start < s.length())
            ret.push_back(s.substr(start,len));
        return ret;
    }
    */
    vector<string> split(const string& s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    string toGoatLatin(string S) 
    {
        string res;
        vector<string> tmp = split(S, ' ');
        for(int i=0;i<tmp.size();i++)
        {
            if('a'==tmp[i][0] || 'e'==tmp[i][0] || 'i'==tmp[i][0] || 'o'==tmp[i][0] || 'u'==tmp[i][0] || 'A'==tmp[i][0] || 'E'==tmp[i][0] || 'I'==tmp[i][0] || 'O'==tmp[i][0] || 'U'==tmp[i][0])
            {
                res+=tmp[i]+"ma";
                res.append(i+1,'a');
            }
            else
            {
                res+=tmp[i].substr(1,tmp[i].size()-1);
                res+=tmp[i][0];
                res+="ma";
                res.append(i+1,'a');
            }
            if(i!=tmp.size()-1)
            {
                res+=' ';
            }
        }
        return res;
    }
};
