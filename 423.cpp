class Solution 
{
public:
    string originalDigits(string s) 
    {
        vector<int> count(26, 0); 
        for (auto c: s)
            count[c - 'a'] ++;	
        vector<int> num(10, 0);

        num[0] = count['z' - 'a'];
        num[2] = count['w' - 'a'];
        num[4] = count['u' - 'a'];
        num[8] = count['g' - 'a'];
        num[5] = count['f' - 'a'] - num[4];
        num[7] = count['v' - 'a'] - num[5];
        num[3] = count['t' - 'a'] - num[2] - num[8];

        num[6] = count['s' - 'a'] - num[7];
        num[1] = count['o' - 'a'] - num[0] - num[2] - num[4];
        num[9] = count['i' - 'a'] - num[5] - num[6] - num[8];
        string ans = "";
        for(int i = 0; i < 10; i ++) 
        {
            ans.append(num[i], '0' + i);
        }
        return ans;
    }
};
