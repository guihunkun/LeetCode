class Solution 
{
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
    {
        int n = A.size();
        move(n, A, B, C);
    }

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if(n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        move(n-1, A, C, B);    // 将A上面n-1个通过C移到B
        C.push_back(A.back());  // 将A最后一个移到C
        A.pop_back();          // 这时，A空了
        move(n-1, B, A, C);     // 将B上面n-1个通过空的A移到C
    }
};
