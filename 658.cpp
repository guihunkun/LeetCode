class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int left = 0, right = arr.size() - k;
        while(left < right) 
        {
            int mid = left + (right - left >> 1);
            if(x - arr[mid] > arr[mid + k] - x ) 
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
