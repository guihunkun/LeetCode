class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        for (auto a : s) ++m[a];
        for (auto a : s) {
            --m[a];
            if (visited[a]) continue;
            while (a < res.back() && m[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            visited[a] = 1;
        }
        return res.substr(1);
    }
};
/*
解法：贪心算法Greedy，用1个HashMap或者数组统计出现的字符。然后再遍历一遍数组, 假设position = 0，每次找到字符比position的小就更新position，同时也更新count，当count[i] == 0的时候，这个字符就是我们要找的结果字符串里的第一个字符。之后因为其他字符的count还都 > 1，继续在s.substring(position + 1)的子串里递归查找第二个字符，注意要在这个子串里把第一个字符清除掉。

*/
