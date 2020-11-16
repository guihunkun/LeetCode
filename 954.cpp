class Solution 
{
public:
    static bool cmp(const int a, const int b)
    {
        return fabs(a) < fabs(b);
    }
    bool canReorderDoubled(vector<int>& A) 
    {
        sort(A.begin(), A.end(), cmp);
        unordered_map<int, int> rec;
        for(auto num : A)
        {
            rec[num]++;
        }
        for(int i = 0; i < A.size(); i++)
        {
            if(rec[A[i]] > 0)
            {
                if(rec[A[i]*2] > 0)
                {
                    rec[A[i]*2]--;
                }
                else
                    return false;
            }
            rec[A[i]]--;
        }
        return true;
    }
};

