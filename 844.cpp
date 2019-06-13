/*
class Solution 
{
public:
    bool backspaceCompare(string S, string T) 
    {
        stack<char> s, t;
        stackstring(s, S);
        stackstring(t, T);
        if(s.size() != t.size())
            return false;
        while(! s.empty())
        {
            if(s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        return true;
    }
    void stackstring(stack<char> & s, string S)
    {
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] != '#')
                s.push(S[i]);
            else if(!s.empty())
                s.pop();
        }
    }
};
*/
class Solution 
{
public:
    bool backspaceCompare(string S, string T) 
    {
        int i =S.size() - 1, j = T.size() - 1;
        int skipS = 0, skipT = 0;
        while(i >= 0 || j >= 0)
        {
            while(i >= 0)
            {
                if(S[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if(skipS > 0)
                {
                    skipS--;
                    i--;
                }
                else
                    break;
            }
            while(j >= 0)
            {
                if(T[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if(skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                    break;
            }
            if(i >= 0 && j >= 0 && S[i] != T[j])
                return false;
            if((i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};
