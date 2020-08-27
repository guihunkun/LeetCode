
class Solution 
{
public:
    string removeDuplicates(string s, int k) 
    {
        string res;
        stack<pair<char, int> >st;
        for(long long i = s.size() - 1; i >= 0; i--) 
        {
            if(!st.empty() && st.top().first == s[i]) 
            {
                st.top().second++;
                if(st.top().second == k) 
                {
                    st.pop();
                }
            } 
            else 
            {
                st.push(make_pair(s[i], 1));
            }
        }
        while(!st.empty())
        {
            auto && top = st.top();
            res += string(top.second, top.first);
            st.pop();
        }
        return res;
    }
};
