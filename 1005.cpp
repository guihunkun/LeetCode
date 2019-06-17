/*
class Solution 
{
public:
    int largestSumAfterKNegations(vector<int>& A, int K) 
    {
        int res = 0;
        int i = 0;
        int mod = K;
        sort(A.begin(), A.end());
        while(i < A.size() && mod > 0 && A[i] < 0)
        {
            A[i] = 0 - A[i];
            mod--;
            i++;
        }
        if(mod > 0)
        {
            if(mod % 2 != 0)
            {
                if(i < A.size())
                    if(i>0 && A[i] > A[i-1])
                        A[i-1] = 0 - A[i-1];
                    else  
                        A[i] = 0 - A[i];
                else
                    A[A.size() - 1] = 0 - A[i];
            }
        }
        for(int nu : A)
            res += nu;
        return res;
    }
};
*/
class Solution 
{
public:
    int largestSumAfterKNegations(vector<int>& A, int K) 
    {
        priority_queue<int,vector<int>,greater<int>> que;
        int N = A.size();
        int sum = 0;
        for(int i=0;i<N;i++) 
            que.push(A[i]);
        for(int i = 1; i <= K; i++)
        {
            int tmp = que.top();
            que.pop();
            que.push(-tmp);
        }
        while(!que.empty())
        {
            sum += que.top();
            que.pop();
        }
        return sum;
    }
};

