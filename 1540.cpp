class Solution 
{
public:
    bool canConvertString(string s, string t, int k) 
    {
        if(s.size() != t.size()) {
            return false;
        }
        auto counts = vector<int>(26);
        int length = s.size();
        for(int i = 0; i < length; i++) 
        {
            int difference = t.at(i) - s.at(i);
            if(difference < 0) {
                difference += 26;
            }
            counts[difference]++;
        }
        for(int i = 1; i < 26; i++) 
        {
            int maxConvert = i + 26 * (counts[i] - 1);
            if(maxConvert > k) {
                return false;
            }
        }
        return true;
    }
};

