class Solution {
public:
    bool isValid(string code) {
        // <A></A>  合法的最短串 长度为7
        if(code.size() < 7 || code[0] != '<' || code.back() != '>') return false;
        stack<string> name;
        for(int i=0; i<code.size(); i++){
            if(code[i] == '<') {
                if(code[i+1] == '!'){
                    // <![CDATA[]]></A>    最短为左边的形式， 所以 i+15 应小于 code.size()
                    if(name.empty() || i+15 >= code.size()) return false;
                    string tem = code.substr(i, 9);
                    int ind = code.find("]]>", i+9);
                    if(tem != "<![CDATA[" || ind == string::npos) return false;
                    i = ind+2;
                } else {
                    string tem="";
                    bool flag = (code[i+1] == '/');
                    i += flag;
                    // 获取当前标签
                    while(++i<code.size() && code[i] != '>'){
                        if(code[i] >= 'A' && code[i] <= 'Z') tem += code[i];
                        else return false;
                    }
                    if(tem.size() < 1 || tem.size() > 9 || i == code.size()) return false;
                    if(flag){
                        // 当前标签为结束标签
                        if(name.empty() || tem != name.top()) return false;
                        name.pop();
                        // 所有代码都应在标签里面
                        if(name.empty() && i != code.size()-1) return false;
                    } // 当前为开始标签
                    else name.push(tem);  
                }
            }
        }
        return name.empty();
    }
};
