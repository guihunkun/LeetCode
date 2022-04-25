class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        if(arr[0] > k) {
            return k;
        }
        int l = 0, r = arr.size();
        while(l < r) 
        {
            int mid = (l + r) >> 1;
            int x = mid < arr.size() ? arr[mid] : INT_MAX;
            if(x - mid - 1 >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return k - (arr[l - 1] - (l - 1) - 1) + arr[l - 1];
    }
};



