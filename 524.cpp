class Solution 
{
private:
    bool isZichuan(string target, string s)
    {   
        //分别从左端开始索引，检测是否为子列
        int i = 0, j = 0;
        while(i < target.size() && j < s.size())
        {
            if(target[i] == s[j])
                i++;
            j++;  
        }
        return i == target.size();
    }

public:
    string findLongestWord(string s, vector<string>& d) 
    {
        string str = "";
        for(int i = 0; i < d.size(); i++)
        {
            int tag = str.length();
            int leng = d[i].length();
            //若字符串更短或者一样长且字母顺序较大的直接舍去
            if(tag > leng || (tag == leng && str.compare(d[i]) < 0))
                continue;
            
            if(isZichuan(d[i], s))
            {
                str = d[i];
            }
        }
        return str;
    }
};
