class Solution {
    int len;
public:
    vector<string> braceExpansionII(string expression) {
        int start = 0;
        len = expression.size();
        auto k = dfs(expression,start);
        vector<string> res;
        for(auto& x:k) res.push_back(x);
        sort(res.begin(),res.end());
        return res;
    }
    unordered_set<string> dfs(string& expression,int& start){
        unordered_set<string> res,t;
        while(start < len && expression[start] != '}'){
            if(expression[start] == '{'){
                auto p = dfs(expression,++start);
                if(t.empty()) t = p;
                else{
                    unordered_set<string> temp;
                    for(auto& x:t){
                        for(auto& y:p){
                            temp.insert((string)x+y);
                        }
                    }
                    t = temp;
                }
            }
            else if(expression[start] == ','){
                for(auto& x:t){
                    res.insert(x);
                }
                t.clear();
                ++start;
            }
            else{
                string s;
                while(start < len && expression[start] >= 'a' && expression[start] <= 'z') s.push_back(expression[start++]);
                if(t.empty()) t.insert(s);
                else{
                    unordered_set<string> temp;
                    for(auto& x:t){
                        temp.insert(x+s);
                    }
                    t = temp;
                }
            }
            if(start >= len || expression[start] == '}'){
                for(auto& x:t) res.insert(x);
            }
        }
        ++start;
        return res;
    }
};
