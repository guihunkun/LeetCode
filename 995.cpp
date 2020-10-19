class Solution 
{
public:
    int ans = 0;
    queue<int> q;
    int minKBitFlips(vector<int>& A, int K) {
        for(int i=0;i<A.size();i++){
            // 维护长度为K的窗口
            if(!q.empty() && q.front() + K == i)
                q.pop();
            //判断当前位置是否需要翻转
            if(q.size()%2 == A[i]){
                if(i + K > A.size()) return -1;
                ans ++;
                q.push(i);
            }
        }
        return ans;
    }
};

