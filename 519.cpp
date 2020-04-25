class Solution {
public:
    int R;
    int C;
    int N;
    unordered_map<int, int> BL; // black list
    Solution(int n_rows, int n_cols) {
        R = n_rows;
        C = n_cols;
        N = R * C;
    }
    int find(int x) {
        if (BL.count(x)) {
            BL[x] = find(BL[x]);
            return BL[x];
        }
        return x;
    }
    vector<int> flip() {
        if (N == 0) return {};
        int k = find(rand() % N);
        BL[k] = --N;
        return {k / C, k % C};
    }
    
    void reset() {
        N = R * C;
        BL.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
