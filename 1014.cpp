class Solution 
{
public:
    /*
    求景点j的分数由两部分组成A[j]-j为固定的，
    要使景点j分数最高即使(A[i]+i)最大即可(i<j)
    */
    int maxScoreSightseeingPair(vector<int>& A) 
    {
        int res = 0, cur = A[0] + 0;
        for(int j = 1; j < A.size(); j++)
        {
            res = max(res, cur + A[j] - j);
            cur = max(cur, A[j] + j);
        }
        return res;
    }
};
