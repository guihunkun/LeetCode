class Solution 
{
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        sort(arr.begin(), arr.end());
        vector<int> pre(arr.size()+1, 0);
        for( int i = 1; i <= arr.size(); i++) {
            pre[i] = pre[i-1] + arr[i-1];
        }
        int max = *max_element(arr.begin(), arr.end());
        int res = 0;
        int diff = target;
        for(int i = 1; i <= max; i++)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int cur = pre[iter - arr.begin()] + (arr.end() - iter)*i;
            if(abs(cur - target) < diff) {
                res = i;
                diff = abs(cur - target);
            }
        }
        return res;
    }
};
