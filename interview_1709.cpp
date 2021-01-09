class Solution 
{
public:
    int getKthMagicNumber(int k) 
    {
        if(k <= 0) 
            return 0;
        
        vector<long long int> nums(k+1, 1);  // 为防止越界，用 long long保存
        int p3 = 0, p5 = 0, p7 = 0;  // 标记"某个素数"的下标
        for(int i = 1; i < k; ++i)
        {
            nums[i] = min(min(3 * nums[p3], 5 * nums[p5]), 7 * nums[p7]);
            if(nums[i] == 3 * nums[p3]) 
                p3++; // p3++是因为由p3所在的素数求得了最小值，故不会再由p3所在的素数求得另一个最小值，下一个最小值可能是3 * nums[p3+1]。下面p5++, p7++同理。
            if(nums[i] == 5 * nums[p5]) 
                p5++;  // 注意此处是if,而不是else if,因为可能3 *nums[p3] == 5 * nums[p5] 或 7 * nums[p7] == 5 * nums[p5]。下面的同理。
            if(nums[i] == 7 * nums[p7]) 
                p7++;
        }
        return nums[k-1];
    }
};
