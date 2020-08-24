class Solution 
{
public:
    int scoreOfParentheses(string S) 
    {
        stack<int> s;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '(')
            {
                s.push(0);
            }
            else
            {
                if(s.top() == 0)
                {
                    s.pop();
                    s.push(1);
                }
                else
                {
                    int sum = 0;
                    while(s.top() != 0)
                    {
                        sum += s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(sum*2);
                }
            }
        }
        int res = 0;
        while(!s.empty())
        {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
