class Solution 
{
public:
    bool rotateString(string A, string B) 
    {
        if(A.size() != B.size())
            return false;
        string s = A + A;
        if(s.find(B) != string::npos)
            return true;
        return false;
    }
};
