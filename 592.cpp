class Solution {
public:
    bool isSign(char c) {
        return c == '+' || c == '-';
    }
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    void simplify(int& n, int& m) {
        if (n == 0) {
            m = 1;
            return;
        }
        int t = __gcd(n, m);
        n /= t;
        m /= t;
    }
    // pair<int, int> first: 分子，second：分母
    pair<int, int> add(const pair<int, int> p1, const pair<int, int> p2) {
        int n1 = p1.first;
        int d1 = p1.second;
        int n2 = p2.first;
        int d2 = p2.second;
        int n = n1 * d2 + n2 * d1;
        int d = d1 * d2;
        simplify(n, d);
        if (n * d < 0) {
            n = -abs(n);
            d = abs(d);
        }
        return {n, d};
    }
    pair<int, int> parse(const string& exp, int l) {
        int sign = exp[l] == '+' ? 1 : -1;
        int i = l + 1;
        int n = 0;
        while (i < exp.size() && exp[i] != '/') {
            n = n * 10 + exp[i] - '0';
            ++i;
        }
        ++i;
        int d = 0;
        while (i < exp.size() && isDigit(exp[i])) {
            d = d * 10 + exp[i] - '0';
            ++i;
        }
        simplify(n, d);
        return {sign * n, d};
    }
    string fractionAddition(string expression) {
        if (expression.empty()) return "";
        string exp = isSign(expression[0]) ? expression : '+' + expression;
        pair<int, int> res{0, 1};
        for (int i = 0; i < exp.size(); ++i) {
            if (isSign(exp[i])) {
                res = add(res, parse(exp, i));
            }
        }
        return to_string(res.first) + "/" + to_string(res.second);
    }
};

