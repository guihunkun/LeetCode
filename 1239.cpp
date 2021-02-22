//leetcode
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Ϊÿһ���ַ�������λ����
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
    // ���ڱ����
    int ans;

    int buildCharBits(string s) {
        // �Ż�����
        if (s.size() > 26) return -1;

        int bit = 0;
        for (auto &i : s) {
            // ���ַ����г�������ͬ�ַ��򷵻�-1��ʾ���ַ������ϸ�
            int mask = 1 << (i - 'a');
            if (bit & mask) return -1;

            bit |= mask;
        }
        return bit;
    }

    // ���ݹ��̡�idx��ʾarr�����ڴ�����ַ������±꣬track��len�ֱ��ʾ�������ַ�����λ�����ͳ���
    void backtrace(vector<string>& arr, vector<int>& bits, int idx, int track, int len) {
        // �����ַ����������ʱ���´�
        if (idx >= arr.size()) {
            ans = max(ans, len);
            return ;
        }

        // ������arr[idx]
        backtrace(arr, bits, idx + 1, track, len);

        // ���arr[idx]�����Ǻϸ�Ĳ��Һʹ�������ַ���û���ظ��ַ�����arr[i]
        if (bits[idx] != -1 && (track & bits[idx]) == 0) {
            backtrace(arr, bits, idx + 1, track | bits[idx], len + arr[idx].size());
        }
    }
};

