/*
class Solution 
{
public:
    vector<string> permutation(string S) 
    {
         vector<string> res;
         dfs(S, 0, res);
         return res;
    }
    void dfs(string& S, int index, vector<string>& res) 
    {
        if(index == S.size()) 
        {
            res.push_back(S);
            return;
        }
        for(int i = index; i < S.size(); ++i) 
        {
            swap(S[i], S[index]);
            dfs(S, index + 1, res);
            swap(S[i], S[index]);
        }
    }
};
*/

/*
class Solution 
{
public:
    vector<string> permutation(string S) 
    {
        sort(S.begin(), S.end());
        vector<string> res;
        res.emplace_back(S);
        while(next_permutation(S.begin(), S.end()))
            res.emplace_back(S);
        return res;
    }
};
*/
class Solution 
{
public:
    vector<string> permutation(string S) 
    {
        vector<string> res;
        if(S.size() == 0)
        {
            return res;
        }
        vector<bool> vis(S.size(), false);
        backtrack(S, "", vis, res);
        return res;
    }
    void backtrack(string& S, string item, vector<bool>& vis, vector<string>& res)
    {
        if(S.size() == item.size())
        {
            res.push_back(item);          
        } else {
            for(int i = 0; i < vis.size(); i++)
            {
                if(!vis[i])
                {
                    item += S[i];
                    vis[i] = true;
                    backtrack(S, item, vis, res);
                    item.pop_back();
                    vis[i] = false;
                }
            }
        }
    }
};
