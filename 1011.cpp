class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // ȷ�����ֲ������ұ߽�
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = (left + right) / 2;
            // need Ϊ��Ҫ���͵�����
            // cur Ϊ��ǰ��һ���Ѿ����͵İ�������֮��
            int need = 1, cur = 0;
            for (int weight: weights) {
                if (cur + weight > mid) {
                    ++need;
                    cur = 0;
                }
                cur += weight;
            }
            if (need <= D) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
