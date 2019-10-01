class Solution {
public:
    #define LL long long
    bool check(string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
    int superpalindromesInRange(string L, string R) {
        LL l = stoll(L), r = stoll(R);
        int ans = 0;

        for (int j = 1; j <= 3; j++) {
            if (j * j >= l && j * j <= r)
                ans++;
        }

        for (int i = 1; i < 10000; i++) {
            string t = to_string(i);
            string rt = t;
            reverse(rt.begin(), rt.end());

            LL s = stoll(t + rt);
            s *= s;
            if (s > r)
                break;

            if (check(to_string(s)) && l <= s && s <= r)
                ans++;

            for (char j = '0'; j <= '9'; j++) {
                s = stoll(t + j + rt);
                s *= s;
                if (check(to_string(s)) && l <= s && s <= r)
                    ans++;
            }
        }
        return ans;
    }
};
/*
首先我们可以构造在 10^9 内的回文数，然后将其平方后判定是否还是回文数。
构造回文数只需要枚举一半数位的数字即可，本题中，枚举 1 至 n{\frac{1}{4}} 即可找到所有满足条件的回文数。
对于枚举的每一个数字 xx，有两种方式构造：xx′xx′ 和 xjx′xjx′，分别判定即可。
注意特判答案 1, 4, 9。
时间复杂度
枚举后只需要 O(logn)O(log⁡n) 的时间即可判定，故总时间复杂度为 O(n14logn)O(n14log⁡n)。
https://www.acwing.com/solution/leetcode/content/569/
*/
