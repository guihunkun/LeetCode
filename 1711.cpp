const int MOD = 1e9 + 7;
class Solution {
    using LL = long long;
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> memo;
        LL ans = 0;
        for (int i = 0;i < deliciousness.size();++i){
            for (int j = 0;j < 22;++j){
                int target = pow(2,j);
                if (target - deliciousness[i] < 0) continue;
                if (memo.count(target - deliciousness[i])){
                    ans += memo[target - deliciousness[i]];
                }
            }
            ++memo[deliciousness[i]];
        }
        ans %= MOD;
        return ans;
    }
};

