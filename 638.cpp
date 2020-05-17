class Solution {
public:
    bool valid(const vector<int>& sp, const vector<int>& needs) {
        for (int i = 0; i < needs.size(); ++i) {
            if (sp[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }
    void backtrace(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs, int cost, int& res) {
        if (cost >= res) return;
        int s = accumulate(needs.begin(), needs.end(), 0);
        if (s == 0) {
            res = min(res, cost);
            return;
        }
        bool match = false;
        for (int i = 0; i < special.size(); ++i) {
            if (valid(special[i], needs)) {
                match = true;
                for (int j = 0; j < needs.size(); ++j) {
                    needs[j] -= special[i][j];
                }
                backtrace(price, special, needs, cost + special[i].back(), res);
                for (int j = 0; j < needs.size(); ++j) {
                    needs[j] += special[i][j];
                }
            }
        }
        // 如果没有找到任何一个合适的礼包，说明就需要单买了
        if (!match) {
            for (int i = 0; i < needs.size(); ++i) {
                cost += price[i] * needs[i];
            }
            res = min(res, cost);
        }
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 先删除掉比单买还不划算的礼包以及个数过大的礼包
        int k = 0;
        for (int i = 0; i < special.size(); ++i) {
            int s = 0;
            bool match = true;
            for (int j = 0; j < price.size(); ++j) {
                s += price[j] * special[i][j];
                if (special[i][j] > needs[j]) {
                    match = false;
                    break;
                }
            }
            if (match && special[i].back() < s) {
                special[k++] = special[i];
            }
        }
        if (k < special.size()) {
            special.erase(special.begin() + k, special.end());
        }
        // 回溯
        int res = INT_MAX;
        backtrace(price, special, needs, 0, res);
        return res;
    }
};
