class Solution 
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int startindex = 0, maxn = 0;
        for(int i = 0; i < houses.size(); i++) 
        {
            int tempmin = INT_MAX;
            for(int j = startindex; j < heaters.size(); j++) 
            {
                if(abs(heaters[j] - houses[i]) <= tempmin) {
                    tempmin = abs(heaters[j] - houses[i]);
                    startindex = j;
                } else {
                    break;
                }
            }
            maxn = max(maxn, tempmin);
        }
        return maxn;
    }
};
/*
分析：先将houses和heaters排序，计算每一个house左右的供暖器的距离最小的那个值，然后将所有的这些最小值中取最大的值。
因为houses和heaters都是排序好的，所以heater[j]与houses[i]的距离应该越来越小，如果突然间变大了，说明不是最小值了，就break掉。这样就能得知最小值。
原文：https://blog.csdn.net/liuchuo/article/details/54586943 
*/
