class Solution 
{
public:
    string removeDuplicates(string S) 
    {
        string s = "";
        if(S.size() <= 1)
            return S;
        for(int i = 0; i < S.size(); i++)
        {
            if(! s.empty() && s.back() == S[i])
                s.pop_back();
            else
                s.push_back(S[i]);
        }
        return s;
    }
};

