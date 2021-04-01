class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        N--;

        int index = 0; // 用于控制乘、除、加、减
        while (N > 0) {
            if (index % 4 == 0) {
                stk.top() *= N;
            } else if (index % 4 == 1) {
                stk.top() /= N;
            } else if (index % 4 == 2) {
                stk.push(N);
            } else {
                stk.push(-N);
            }
            index++;
            N--;
        }

        // 把栈中所有的数字依次弹出求和
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};

