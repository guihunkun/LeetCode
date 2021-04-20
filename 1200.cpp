class Solution 
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {

        //排序
        sort(arr.begin(), arr.end());
        //找出最小绝对差
        int min_diff = INT_MAX;
        for(int i = 0; i < arr.size() - 1; ++i) {
            min_diff = std::min(min_diff, arr.at(i + 1) - arr.at(i));
        }

        //找最小绝对差的元素对
        vector<vector<int>> vv;
        vv.reserve(arr.size());
        for(int i = 0; i < arr.size() - 1; ++i)
        {
            if (min_diff == (arr.at(i + 1) - arr.at(i))) {
                vv.push_back(vector<int>{arr.at(i), arr.at(i + 1)});
            }
        }

        return vv;
    }
};
