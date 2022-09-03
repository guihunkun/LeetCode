class Solution 
{
private:
    int numsSorted[100000]; //用于归并的辅助数组，这里值即定义在外面，省的每次归并都要重新申请
    //统计出某个数字左边比它小的数字个数
    void merging(vector<int>& ins, vector<int>& id, vector<int>& leftSmaller, int low, int high)
    {
        //low 是下标开始位置，high 是下标结束位置的下一个位置
        if (low - high >= -1) {
            return;
        }
        int mid = (low + high) >> 1;
        merging(ins, id, leftSmaller, low, mid);
        merging(ins, id, leftSmaller, mid, high);
        int p = 0;
        int q = low, r = mid;
        //非递增归并排序，只移动下标数组，不改变原数组
        while (q < mid && r < high) {
            if (ins[id[q]] < ins[id[r]]) {
                leftSmaller[id[r]] += mid - q;
                numsSorted[p++] = id[r++];
            } else {
                numsSorted[p++] = id[q++];
            }
        }
        while (r < high) {
            numsSorted[p++] = id[r++];
        }
        while (q < mid) {
            numsSorted[p++] = id[q++];
        }
        for (int i = low; i < high; ++i) {
            id[i] = numsSorted[i - low];
        }
        return;
    }
public:
    int createSortedArray(vector<int>& instructions) 
    {
        int mod = 1e9 + 7;
        int n = instructions.size();
        int repeat[100001] = { 0 }; //用于统计某数字左边和它相同的数字个数
        vector<int> id(n);
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
        vector<int> leftSmaller(n, 0);
        merging(instructions, id, leftSmaller, 0, n);
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            //总数减去小的再减去相等的剩下的就是大的
            ans += min(leftSmaller[i], i - leftSmaller[i] - repeat[instructions[i]]);
            ++repeat[instructions[i]];
        }
        return ans % mod;
    }
};


