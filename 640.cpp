class Solution {
public:
    #define NO "No solution"
    #define INF "Infinite solutions"
    void helper(string exp, int& num, int& fac) {
        int sign = 1; // 符号
        int k = 0; // 系数值
        bool is_x = false; // 系数是否隶属于x
        for (int i = 0; i < exp.size(); ++i) {
            char c = exp[i];
            if (c == '+' || c == '-') {
                if (is_x) {
                    fac += k * sign;
                } else {
                    num += k * sign;
                }
                sign = c == '+' ? 1 : -1;
                k = 0;
                is_x = false;
            } else if (c >= '0' && c <= '9') {
                k = k * 10 + c - '0';
            } else if (c == 'x') {
                is_x = true;
                if (k == 0 && (i == 0 || exp[i - 1] != '0')) {
                    k = 1;
                }
            }
        }
    }
    string solveEquation(string equation) {
        int ind = equation.find('=');
        if (ind == -1) return NO;        
        int num1 = 0, fac1 = 0;
        int num2 = 0, fac2 = 0;
        helper(equation.substr(0, ind) + "+", num1, fac1);
        helper(equation.substr(ind + 1) + "+", num2, fac2);
        int delta_x = fac2 - fac1;
        int delta_n = num1 - num2;
        if (delta_x == 0) {
            return (delta_n == 0) ? INF : NO;
        }
        return "x=" + to_string(delta_n / delta_x);
    }
};
