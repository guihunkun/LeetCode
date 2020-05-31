class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> elms, ops;

        for(int v : nums) {
            int pos, paths = 1;

            /* 一、二分查找 “生长点”。 */
            if(elms.size() == 0 || v > elms.back().back()) {
                pos = elms.size();
            } else {
                pos = lower_bound(elms.begin(), elms.end(), v, [](vector<int> &a, const int &b){
                    return a.back() < b;
                }) - elms.begin();
            }

            /* 二、二分查找 “可以插入的最大尾数”。*/
            if(pos > 0) {
                int pre = pos - 1;
                int p2 = upper_bound(elms[pre].begin(), elms[pre].end(), v, greater<int>()) - elms[pre].begin();
                paths = ops[pre].back() - (p2? ops[pre][p2-1] : 0);
            }

            /* 三、计算以元素 v 结尾的, 长度为 pos + 1 的上升子序列个数，并累加前缀和。*/
            if(pos == elms.size()) {
                elms.push_back({v}), ops.push_back({paths});
            } else {
                elms[pos].push_back(v);
                ops[pos].push_back(paths + ops[pos].back());
            }
        }

        return ops.size()? ops.back().back() : 0;
    }
};
