//leetcode
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int MODULO = 1000000007;
        int length = nums.size();
        auto counts = vector<int>(length);
        for (auto request: requests) {
            int start = request[0], end = request[1];
            counts[start]++;
            if (end + 1 < length) {
                counts[end + 1]--;
            }
        }
        for (int i = 1; i < length; i++) {
            counts[i] += counts[i - 1];
        }
        sort(counts.begin(), counts.end());
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = length - 1; i >= 0 && counts[i] > 0; i--) {
            sum += (long long)nums[i] * counts[i];
        }
        return sum % MODULO;
    }
};

