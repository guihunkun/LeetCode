//leetcode
class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        // 为每一个字符串构建位向量
        int sz = arr.size();
        vector<int> bits(sz, 0);
        for (int i = 0; i < sz; ++i) {
            bits[i] = buildCharBits(arr[i]);
        }

        ans = INT_MIN;
        backtrace(arr, bits, 0, 0, 0);
        return ans;
    }

private:
    // 用于保存答案
    int ans;

    int buildCharBits(string s) 
    {
        // 优化技巧
        if (s.size() > 26) return -1;

        int bit = 0;
        for (auto &i : s) {
            // 若字符串中出现了相同字符则返回-1表示该字符串不合格
            int mask = 1 << (i - 'a');
            if (bit & mask) return -1;

            bit |= mask;
        }
        return bit;
    }

    // 回溯过程。idx表示arr中正在处理的字符串的下标，track和len分别表示串联后字符串的位向量和长度
    void backtrace(vector<string>& arr, vector<int>& bits, int idx, int track, int len) 
    {
        // 所有字符串处理完毕时更新答案
        if (idx >= arr.size()) {
            ans = max(ans, len);
            return ;
        }
        // 不串联arr[idx]
        backtrace(arr, bits, idx + 1, track, len);
        // 如果arr[idx]本身是合格的并且和串联后的字符串没有重复字符则串联arr[i]
        if (bits[idx] != -1 && (track & bits[idx]) == 0) {
            backtrace(arr, bits, idx + 1, track | bits[idx], len + arr[idx].size());
        }
    }
};
