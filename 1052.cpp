class Solution 
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }
        int increase = 0;
        for (int i = 0; i < X; i++) {
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for (int i = X; i < n; i++) {
            increase = increase - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
};

