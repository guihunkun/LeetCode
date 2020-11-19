class Solution 
{
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        if(arr.empty())
        {
            return -1;
        }
        if(arr.size()==1)
        {
            return 0;
        }
        int left = 0;
        // [0...left]有序
        for(int i = 0; i < arr.size()-1; i++)
        {
            if(arr[i+1] < arr[i])
            {
                left = i;
                break;
            }
            if(i == arr.size()-1)
            {
                return 0;
            }
        }
        // [right ... arr.szie()-1]有序
        int right = arr.size()-1;
        for(int i = arr.size()-1; i > 0; i--)
        {
            if(arr[i-1] > arr[i])
            {
                right = i;
                break;
            }
            if(i == 1)
            {
                return 0;
            }
        }
        // 删除[left+1, arr.size()-1] 或者删除[0, right-1]
        int res = min((int)arr.size()-left-1, right); 
        int l = 0, r = right;
        // 左右两边各保留一部分
        while(l <= left && r <= arr.size() - 1) 
        {
            if(arr[l] <= arr[r]) {
                // 删除 [i+1...j-1]
                res = min(res, r - l - 1);
                l++;
            } else {
                r++;
            }
        }
        return res;
    }
};
