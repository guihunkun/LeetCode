class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        N--;

        int index = 0; // ���ڿ��Ƴˡ������ӡ���
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

        // ��ջ�����е��������ε������
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};

