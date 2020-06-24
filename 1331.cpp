class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<pair<int, int>> ais;
        for (int i = 0; i < arr.size(); ++i)
            ais.emplace_back(arr[i], i);
        sort(ais.begin(), ais.end());
        
        vector<int> ans(arr.size());
        int rank = 1, pre = ais[0].first;
        for (auto ai : ais) {
            if (ai.first == pre) 
                ans[ai.second] = rank;
            else {
                ans[ai.second] = ++rank;
                pre = ai.first;
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(arr.begin(), arr.end());
        int len = unique(arr.begin(), arr.end()) - arr.begin();
        for(int& a : ans)
            a = lower_bound(arr.begin(), arr.begin() + len, a) - arr.begin() + 1;
        return ans;
    }
};
*/
