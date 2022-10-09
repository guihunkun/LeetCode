//leetcode
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long sum = 0;
        for(int e: nums) sum += (long long)e;
        long long mod = sum % (long long)p;

        if(mod == 0ll) return 0;

        int res = nums.size();
        unordered_map<long long, int> table;
        table[0ll] = -1;

        sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += (long long)nums[i];
            long long curmod = sum % (long long)p;
            table[curmod] = i;

            long long targetmod = curmod >= mod ? (curmod - mod) : (curmod - mod + p);
            if(table.count(targetmod))
                res = min(res, i - table[targetmod]);
        }
        return res == nums.size() ? -1 : res;
    }
};

