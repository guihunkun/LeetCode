class Solution 
{
public:
    string replaceSpaces(string S, int length) 
    {
        int i = length - 1;
        int j = S.size() - 1;
        while(i >= 0) 
        {
            if(S[i] == ' ') {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
                i--;
            } else {
                S[j--] = S[i--];
            }
        }
        return S.substr(j+1);
    }
};
