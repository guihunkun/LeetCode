class Solution {
public:
    vector<int> psum;
    int tot = 0;
    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<int> w) {
        for (int x : w) {
            tot += x;
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int>{0, tot - 1};
    }

    int pickIndex() {
        int targ = uni(rng);

        int lo = 0, hi = psum.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
