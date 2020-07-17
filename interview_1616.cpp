class Solution {
public:
    vector<int> subSort(vector<int>& nums) {

        vector<int> index_arr(nums.size());
        for (int i = 0; i < index_arr.size(); ++i)
        {
            index_arr.at(i) = i;
        }

        stable_sort(index_arr.begin(), index_arr.end(), [&nums](int i, int j) {
            return nums.at(i) < nums.at(j);
        });

        int begin = -1;
        int end = -2;

        for (int i = 0; i < index_arr.size(); ++i)
        {
            if (index_arr.at(i) != i)
            {
                if (begin == -1)
                {
                    begin = i;
                }

                end = i;
            }
        }

        if(begin < 0)
        {
            return vector<int>{-1, -1};
        }

        return vector<int>{begin, end};
    }
};

