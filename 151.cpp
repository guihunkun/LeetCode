/*
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
*/
    
    
class Solution 
{
public:
    string reverseWords(string s) 
    {
        stack<string> record;
        string word;
        int l, r;
        for(l = 0; l < s.size(); l++)
        {
            if(s[l] != ' ')
                break;
        }
        for(r = s.size() - 1; r >=0; r--)
            if(s[r] != ' ')
                break;
        for(; l <= r; l++)
        {
            if(s[l] == ' ' && s[l + 1] != ' ')
            {
                record.push(word);
                word = "";
            }
                
            else if(s[l] != ' ')
            {
                word += s[l];
            }
        }
        record.push(word);
        string res;
        while(!record.empty())
        {
            res += record.top();
            res += ' ';
            record.pop();
        }
        res.pop_back();
        return res;
    }
};
