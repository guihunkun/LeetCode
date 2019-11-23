/*
class Solution 
{
public:
    string reverseOnlyLetters(string S) 
    {
        vector<char> record;
        for(int i = 0; i < S.size(); i++)
        {
            if((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
            {
                record.push_back(S[i]);
            }
        }
        reverse(record.begin(), record.end());
        int j = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
            {
                S[i] = record[j];
                j++;
            }
        }
        return S;
    }
};
*/
class Solution 
{
public:
    string reverseOnlyLetters(string S) 
    {
        int j = S.size() - 1;
        string res;
        for(int i = 0; i < S.size(); i++)
        {
            if((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
            {
                while(!((S[j] >= 'A' && S[j] <= 'Z') || (S[j] >= 'a' && S[j] <= 'z')))
                {
                    j--;
                }
                res += S[j];
                j--;
            }
            else
            {
                res += S[i];
            }
        }
        return res;
    }
};
