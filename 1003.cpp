class Solution 
{
public:
    bool isValid(string s) 
    {                       //彩色连珠  消消乐  碰碰消 的思想
        vector<char> rec;
        int recLen = 0;
        for (auto c: s)
        {
            if (c=='c' && recLen >= 2 && rec[recLen - 2]=='a' && rec[recLen - 1]=='b')
            {
                rec.pop_back();
                rec.pop_back();
                recLen -= 2;
            }
            else
            {
                rec.push_back(c);
                recLen += 1;
            }
        }

        return recLen == 0;
    }
};
