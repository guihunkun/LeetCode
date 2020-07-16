class Solution 
{
public:
    vector<int> pancakeSort(vector<int>& A) 
    {
        vector<int> res;
        int N = A.size();
        for(int i = N-1; i>0; --i)
        {
            int j = max_element(A.begin(), A.begin()+i+1) - A.begin();
            if(j > 0)
            {
                reverse(A.begin(), A.begin()+j+1);
                res.push_back(j+1);
            }
            reverse(A.begin(), A.begin()+i+1);
            res.push_back(i+1);
        }
        return res;
    }
};
