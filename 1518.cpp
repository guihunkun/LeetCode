class Solution 
{
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int bottle = numBottles, res = numBottles;
        while(bottle >= numExchange) {
            bottle -= numExchange;
            ++res;
            ++bottle;
        }
        return res;
    }
};
