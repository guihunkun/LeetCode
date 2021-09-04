
class Solution 
{
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        stack<int> stk;
        stk.push(INT_MAX);
        int res = 0;
        for(auto e : arr) 
        {
            while(stk.top() <= e) {  // c  >  b <  a， case2
                int top = stk.top();
                stk.pop();
                res += top * std::min(e, stk.top());
            }
            stk.push(e);
        }
        
        int top = stk.top();
        stk.pop();
        // 单调递减队列,
        while(!stk.empty()) 
        {
            int tmp_top = stk.top();
            if(tmp_top == INT_MAX) {
                break;
            }
            res += top * tmp_top;
            top = tmp_top;
            stk.pop();
        }
        return res;
    }
};

