class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int res = arr[0], count = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] == res) {
                if(++count > arr.size()/4) {
                    return res;
                }
            } else {
                res = arr[i];
                count = 1;
            }
        }
        return res;
    }
};

