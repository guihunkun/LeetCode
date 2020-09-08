class Solution 
{
public:
    int *ne;
    void arrange(string& s, int l, int r) 
    {
        if(l <= r) 
        {
            multiset<string> strs; // 注意，必须是 "multiset"，以便保持重复的字符串
            for(int i = l; i <= r;) 
            {
                arrange(s, i+1, ne[i]-1);
                strs.insert(s.substr(i, ne[i] - i + 1));
                i = ne[i] + 1;
            }
            int p = l;
            for(auto it = strs.rbegin(); it != strs.rend(); ++it)
                for(char c : *it)
                    s[p++] = c;
        }
    }
    string makeLargestSpecial(string s) 
    {
        ne = new int[s.size()];
        stack<int> st;
        for(int i = 0; i < s.size(); ++i) 
        {
            if(s[i] == '1') {
                st.push(i);
            } else {
                ne[st.top()] = i;
                st.pop();
            }
        }
        arrange(s, 0, (int)s.size() - 1);
        return s;
    }
};
