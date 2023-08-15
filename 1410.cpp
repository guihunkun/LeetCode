class Solution 
{
public:
    unordered_map<string, string> strChangMap = {{"&quot;", "\""},{"&apos;", "'"},{"&amp;", "&"},{"&gt;", ">"},{"&lt;", "<"},{"&frasl;", "/"}};
    string entityParser(string& text) 
    {
        //InitTmpVec(tmpVec);
        string resStr = text;
        // 找起始位置
        int beginPos = resStr.find('&');
        int endPos = resStr.find(';');
        // -1 找不到 & 或者 ;的时候就可以退出
        while((endPos != -1) && (beginPos != -1)) 
        {
            string strTmp = resStr.substr(beginPos, endPos - beginPos + 1);
            if(strChangMap.find(strTmp) != strChangMap.end()) {
                resStr.replace(resStr.begin() + beginPos, resStr.begin() + endPos + 1, strChangMap[strTmp]);
            }
            beginPos = resStr.find('&', beginPos + 1);
            endPos = resStr.find(';', beginPos + 1);
        }
        return resStr;
    }    
};

