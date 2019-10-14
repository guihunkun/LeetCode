/*
class Solution 
{
public:
    int longestWPI(vector<int>& hours) 
    {
        int sum, res = 0;
        vector<int> record;
        for(int i = 0; i < hours.size(); i++)
        {
            if(hours[i] > 8)
                record.push_back(1);
            else
                record.push_back(-1);
        }
        for(int i = 0; i < hours.size(); i++)
        {
            sum = 0;
            for(int j = i; j < hours.size(); j++)
            {
                sum += record[j];
                if(sum > 0 && (j-i+1) > res)
                    res = (j-i+1);
            }
        }
        return res;
    }
};
*/
/*
class Solution 
{
public:
    int longestWPI(vector<int>& hours) 
    {
        int n = hours.size();
        vector<int> sum(n + 1, 0);

        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);

        int ans = 0;
        vector<int> mono;
        mono.push_back(0);

        for (int i = 1; i <= n; i++) {
            int l = 0, r = mono.size() - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (sum[mono[mid]] < sum[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (sum[mono[l]] < sum[i])
                ans = max(ans, i - mono[l]);

            if (sum[i] < sum[mono[mono.size() - 1]])
                mono.push_back(i);
        }

        return ans;
    }
};
*/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int sum = 0, ans = 0;

        unordered_map<int, int> visited;
        for (int i = 0; i < n; i++) {
            sum += (hours[i] > 8 ? 1 : -1);
            if (sum > 0)
                ans = i + 1;
            else {
                if (visited.find(sum - 1) != visited.end())
                    ans = max(ans, i - visited[sum - 1]);
                if (visited.find(sum) == visited.end())
                    visited[sum] = i;
            }
        }

        return ans;
    }
};
/*
(贪心，哈希表) O(n)

我们将大于 8 的数字看做 1，小于等于 8 的数字看做 -1。
我们用一个变量维护当前的前缀和 sum，并维护一个哈希表 visited 记录某些前缀和的位置。
从开头遍历数组，如果 sum > 0，则显然答案直接更新为 i + 1。
否则，我们在哈希表中查看是不是有 sum - 1 的 key，如果有，则更新 ans = max(ans, i - visited[sum - 1])；然后如果哈希表中没有 sum 的 key，则新增 visited[sum] = i。
为什么我们只需要找 sum - 1 就可以了呢？这是因为任何一个小于 0 的前缀和，如果能找到满足条件的左端点，其最优的左端点一定是值等于 sum - 1 且下标 最小 的那个位置。其正确性很容易证明，任何一个小于 0 的前缀和，如果能找到满足条件的左端点，前缀和必定都是经过若干次降低升高，然后到当前的 sum 的，而且升高降低的过程一定是连续的，所以 第一次 降低到 sum - 1 的位置是最优的（不可能有第一次升高到 sum - 1 的位置）。
时间复杂度

每个位置遍历一次，哈希表单次操作的时间复杂度为常数，故总时间复杂度为 O(n)
。
空间复杂度

哈希表需要额外 O(n)
 的空间。
*/
