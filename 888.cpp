class Solution 
{
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        int sa = 0, sb = 0;
        set<int> setB;
        vector<int> res;
        for(int i = 0; i < A.size(); i++)
            sa += A[i];
        for(int i = 0; i < B.size(); i++)
        {
            sb += B[i];
            setB.insert(B[i]);
        }
        int delta = (sb - sa )/2;
        for(int i = 0; i < A.size(); i++)
            if(setB.find(A[i] + delta) != setB.end())
            {
                res.push_back(A[i]);
                res.push_back(A[i] + delta);
                break;
            }
        return res;
    }
};
