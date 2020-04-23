class Solution 
{
public:
    int findMinMoves(vector<int>& machines) 
    {
        if(machines.size() < 1) 
        {
            return -1;
        }
        int size = machines.size();
        int sum = 0;
        for(int i = 0; i < size; i++) 
        {
            sum += machines[i]; //生成预处理数组
        }
        if(sum % size != 0) 
        {
            return -1;
        }
        int avg = sum / size;
        int leftSum = 0;
        int res = 0;
        for(int i = 0; i < size; i++) 
        {
            int L = i * avg - leftSum;//i左边的需要的数目-累加和
            int R = (size - i - 1) * avg - (sum - leftSum - machines[i]);//i右边的需要数目-累加和
            if(L > 0 && R > 0) 
            { //如果L > 0，R > 0 ，则两边都少了衣服，瓶颈在于两者之和
                res = std::max(L + R, res);
            } 
            else 
            { //其它情况的瓶颈都在于两者的绝对值的最大值
                res = std::max(std::max(std::abs(L), std::abs(R)), res);
            }
            leftSum += machines[i];
        }
        return res;
    }
};
