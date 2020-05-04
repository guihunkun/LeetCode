class Solution {
public:
    using ll = long long;
    ll tol(const string& s) {
        ll res = 0;
        for (auto c : s) {
            res = 10 * res + (ll)(c - '0');
        }
        return res;
    }
    ll abs(ll x) {
        if (x > 0) return x;
        return -x;
    }
    string nearestPalindromic(string n) {
        ll m = tol(n);
        ll d = LLONG_MAX;
        int s = n.size();
        int md = s / 2;
        int ml = (s + 1) / 2;
        ll h = tol(n.substr(0, ml));
        ll r = 0;
        ll t;
        // 第1个数 1001
        t = (ll)pow(10, s) + 1;
        if (t != m && abs(t - m) <= d) {
            d = abs(t - m);
            r = t;
        }
        // 第2、3、4个数，分别为131、121、111
        for (int k = 1; k >= -1; --k) {
            ll t1 = h + k;
            ll t2 = 0;
            if (ml != md) t1 /= 10;
            while (t1 > 0) {
                t2 = t2 * 10 + (t1 % 10);
                t1 /= 10;
            }
            t = (h + k) * (ll)pow(10, md) + t2;
            if (t != m && abs(t - m) <= d) {
                d = abs(t - m);
                r = t;
            }
        }
        // 第五个数 99
        t = (ll)pow(10, s - 1) - 1;
        if (t != m && abs(t - m) <= d) {
            d = abs(t - m);
            r = t;
        }
        string res;
        while (r > 0) {
            res += (r % 10) + '0';
            r /= 10;
        }
        reverse(res.begin(), res.end());
        if (res.empty()) return "0";
        return res;
    }
};
