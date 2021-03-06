class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> large;
        int mini = 0x7fffffff;
        for (auto& it : nums) {
            it = (it & 1) ? it << 1 : it;
            large.push(it);
            mini = min(mini,it);
        }
        int ret = large.top() - mini;
        while (!large.empty() && !(large.top() & 1)) {
            int temp = large.top() >> 1;
            large.pop();
            large.push(temp);
            mini = min(temp, mini);
            ret = min(ret, large.top() - mini);
        }
        return ret;
    }
};
