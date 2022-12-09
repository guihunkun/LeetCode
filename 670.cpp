class Solution 
{
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        vector<int> rightMax(s.size(), 0);
        int mx = s.size() - 1;
        for(int i = s.size() - 1; i >= 0; i--) 
        {
            if(s[i] > s[mx]) 
            {
                mx = i;
            }
            rightMax[i] = mx;
        }

        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] != s[rightMax[i]]) 
            {
                swap(s[i], s[rightMax[i]]);
                break;
            }
        }
        return stoi(s);
    }
};


