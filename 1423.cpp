class Solution 
{
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int sum = 0;
        for(auto num : cardPoints) {
            sum += num;
        }
        int n = cardPoints.size();
        int window = 0;
        for(int i = 0; i < n - k; i++) {
            window += cardPoints[i];
        }
        int minW = window;
        for(int i = n-k; i < n; i++) {
            window += cardPoints[i];
            window -= cardPoints[i-n+k];
            minW = min(minW, window);
        }
        return sum - minW;
    }
};
