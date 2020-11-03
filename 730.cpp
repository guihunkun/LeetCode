class Solution {
public:
    string srcKey = "abcd";
    const int def = 1e9 + 7;

    int dfs(string &s, int start, int end, vector<vector<int>>& mem)
    {
        if (start > end) {
            return 0;
        }
        if (mem[start][end] != -1) {
            return mem[start][end];
        }
        long long count = 0;
        string scalc = s.substr(start, end - start + 1);
        for (auto c : srcKey) {
            // 查找该字符第一次出现的位置和最后一次出现的位置
            string sc = "";
            sc += c;
            if (scalc.find(sc) == string::npos) continue;
            int b = scalc.find_first_of(sc) + start;
            int e = scalc.find_last_of(sc) + start;

            if (b != e) {
                count += dfs(s, b + 1, e - 1, mem) + 2;
            } else {
                count += dfs(s, b + 1, e - 1, mem) + 1;
            }
        }
        mem[start][end] = count % def;
        return mem[start][end];
    }

    int countPalindromicSubsequences(string S) {
        int n = S.size();
        vector<vector<int>> mem(n, vector(n, -1));
        return dfs(S, 0, n - 1, mem);
    }
};
