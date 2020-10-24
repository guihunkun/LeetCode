class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T);
        int last = 0, ret = 0, pre = 0;
        for (vector<int>& it : clips) {
            if (it[0] < T) {
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        for (int i = 0; i < T; i++) {
            last = max(last, maxn[i]);
            if (i == last) {
                return -1;
            }
            if (i == pre) {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};
