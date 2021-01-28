class Solution 
{
public:
    string compressString(string S) 
    {
        string res;
        for(int i = 0; i < S.size(); i++)
        {
            char c = S[i];
            int j = i + 1;
            while(j < S.size() && S[j] == c) {
                j++;
            }
            res += c+ to_string(j-i);
            i = j-1;
        }
        return res.size() < S.size() ? res : S;
    }
};
