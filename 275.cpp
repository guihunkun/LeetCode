class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        if(citations.size() == 0)
            return 0;
        int res = 0;
        int left = 0, right = citations.size() - 1;
        int len = citations.size(); 
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(citations[mid] >= len - mid)
            {
                res = len - mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return res;
    }
};
