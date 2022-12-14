class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> res;
        if(s.empty() || s.length() < 10) 
        {
            return res; 
        }
        map<string, int> seq_count;
        /*
        AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT
        0                      ^       ^
                     s.length() - 9 s.length() - 1
        */
        for(int i = 0; (i < s.length() - 9); i++) 
        {
            seq_count[s.substr(i, 10)]++;
        }
        for(auto const& seq : seq_count) 
        {
            if(seq.second > 1) 
            {
                res.push_back(seq.first);
            }
        }
        return res;
    }
};
