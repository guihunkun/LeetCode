using PCI = pair<char, int>;

class Solution {
private:
    vector<PCI> weight;
    vector<int> suffix_sum_min, suffix_sum_max;
    vector<int> lead_zero;
    bool used[10];

public:
    int pow10(int x) {
        int ret = 1;
        for (int i = 0; i < x; ++i) {
            ret *= 10;
        }
        return ret;
    }

    bool dfs(int pos, int total) {
        if (pos == weight.size()) {
            return total == 0;
        }
        if (!(total + suffix_sum_min[pos] <= 0 && 0 <= total + suffix_sum_max[pos])) {
            return false;
        }
        for (int i = lead_zero[pos]; i < 10; ++i) {
            if (!used[i]) {
                used[i] = true;
                bool check = dfs(pos + 1, total + weight[pos].second * i);
                used[i] = false;
                if (check) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char, int> _weight;
        unordered_set<char> _lead_zero;
        for (const string& word: words) {
            for (int i = 0; i < word.size(); ++i) {
                _weight[word[i]] += pow10(word.size() - i - 1);
            }
            if (word.size() > 1) {
                _lead_zero.insert(word[0]);
            }
        }
        for (int i = 0; i < result.size(); ++i) {
            _weight[result[i]] -= pow10(result.size() - i - 1);
        }
        if (result.size() > 1) {
            _lead_zero.insert(result[0]);
        }

        weight = vector<PCI>(_weight.begin(), _weight.end());
        sort(weight.begin(), weight.end(), [](const PCI& u, const PCI& v) {
            return abs(u.second) > abs(v.second);
        });
        int n = weight.size();
        suffix_sum_min.resize(n);
        suffix_sum_max.resize(n);
        for (int i = 0; i < n; ++i) {
            vector<int> suffix_pos, suffix_neg;
            for (int j = i; j < n; ++j) {
                if (weight[j].second > 0) {
                    suffix_pos.push_back(weight[j].second);
                }
                else if (weight[j].second < 0) {
                    suffix_neg.push_back(weight[j].second);
                }
                sort(suffix_pos.begin(), suffix_pos.end());
                sort(suffix_neg.begin(), suffix_neg.end());
            }
            for (int j = 0; j < suffix_pos.size(); ++j) {
                suffix_sum_min[i] += (suffix_pos.size() - 1 - j) * suffix_pos[j];
                suffix_sum_max[i] += (10 - suffix_pos.size() + j) * suffix_pos[j];
            }
            for (int j = 0; j < suffix_neg.size(); ++j) {
                suffix_sum_min[i] += (9 - j) * suffix_neg[j];
                suffix_sum_max[i] += j * suffix_neg[j];
            }
        }

        lead_zero.resize(n);
        for (int i = 0; i < n; ++i) {
            lead_zero[i] = (_lead_zero.count(weight[i].first) ? 1 : 0);
        }
        
        memset(used, false, sizeof(used));
        return dfs(0, 0);
    }
};
