/*
class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {

        vector<int> presum = {0};
        for(int e: arr) 
            presum.push_back(presum.back() + e);
        int res = 0;
        for(int i = 0; i < arr.size(); i ++)
            for(int sz = 1; i + sz - 1 < arr.size(); sz += 2)
                res += presum[i + sz] - presum[i];
        return res;
    }
};
*/
class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {

        int res = 0;
        for(int i = 0; i < arr.size(); i ++)
        {
            int left = i + 1, right = arr.size() - i,
                left_even = (left + 1) / 2, right_even = (right + 1) / 2,
                left_odd = left / 2, right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
};

