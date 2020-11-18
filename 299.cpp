class Solution 
{
public:
    string getHint(string secret, string guess) 
    {
        int acnt = 0;
        int bcnt = 0;
        unordered_map<char, int> um;
        for(int i = 0; i < secret.size(); i++) 
        {
            um[secret[i]]++;
            acnt += (secret[i] == guess[i]);
        }
        for(auto& c : guess) 
        {
            bcnt += (um[c]-- > 0);
        }
        bcnt -= acnt;
        return to_string(acnt) + "A" + to_string(bcnt) + "B";
    }
};
