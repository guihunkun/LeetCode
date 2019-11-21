class Solution 
{
public:
    bool buddyStrings(string A, string B) 
    {
        if(A.size() != B.size())
        {
            return false;
        }
        vector<int> index;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] != B[i])
            {
                index.push_back(i);
            }
            if(index.size() > 2)
            {
                return false;
            }
        }
        set<char> record(A.begin(), A.end());
        if(index.size() == 0)
        {
            return record.size() < A.size();
        }
        else if(index.size() == 2)
        {
            return A[index[0]] == B[index[1]] && A[index[1]] == B[index[0]];
        }
        return false;        
    }
};
