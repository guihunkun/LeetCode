class Solution 
{
public:
    string acc;
public:
    string removeOuterParentheses(string S) 
    {
        string answer = "";
        int numOpenParens = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if ( S[i] == '(' ) {
                if (numOpenParens != 0)
                    answer.push_back('(');
                numOpenParens += 1;
            } else {
                numOpenParens -= 1;
                if (numOpenParens != 0)
                    answer.push_back(')');
            }
        }
        return answer;
    }
};
