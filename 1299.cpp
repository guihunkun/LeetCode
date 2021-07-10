
class Solution 
{
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int maxRight = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        for(int i = arr.size()-2; i >= 0; i--)
        {
            int num = arr[i];
            arr[i] = maxRight;
            maxRight = max(maxRight, num);
        }
        return arr;
    }
};

