class Solution {
public:
    string reverseWords(string s) {
        stack<string> words = collectWords(s);
        string res = "";
        while (!words.empty()) {
            res += words.top();
            res += ' ';
            words.pop();
        }
        res.pop_back();
        
        return res;
    }
    
    stack<string> collectWords(string str) {
        // Two-pointer approach
        stack<string> words;
        int l = 0; int r = 0;
        while (l < str.size() && r < str.size()) {
            if (str[r] == ' ') {
                if (r > 0 && str[r-1] != ' ') {        // This ensures we get rid of all extra spaces
                    words.push(str.substr(l, r-l));
                    l = r;
                }
                l++; r++;
            } else {
                if (r == str.size()-1) {
                    words.push(str.substr(l, r-l+1));
                }
                r++;
            }
        }
        return words;
    }
};
