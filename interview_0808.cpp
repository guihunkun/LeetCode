class Solution 
{
public:
    void backtrack(const int len, map<char, int>& rec, string pre, vector<string>& res)
    {
        if(pre.size() == len)
        {
            res.push_back(pre);
            return;
        }
        auto iter = rec.begin();
        for(; iter != rec.end(); iter++)
        {
            if(iter->second)
            {
                (iter->second)--;
                backtrack(len, rec, pre + iter->first, res);
                (iter->second)++;
            }
        }
        return;
    }
    vector<string> permutation(string S) 
    {
        vector<string> res;
        map<char, int> rec;
        for(int i = 0; i < S.size(); i++)
        {
            if(rec.count(S[i])) {
                rec[S[i]]++;
            } else {
                rec[S[i]] = 1;
            }
        }
        backtrack(S.size(), rec, "", res);
        return res;
    }
};
