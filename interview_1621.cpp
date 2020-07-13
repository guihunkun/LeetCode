class Solution 
{
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) 
    {
        
        int sum1 = 0;
        for(int i = 0; i < array1.size(); ++i)
        {
            sum1 += array1.at(i);
        }
        int sum2 = 0;
        // unordered_set<int> set; //array2存入set
        // set.reserve(array2.size() * 4);
        set<int> set;
        for(int i = 0; i < array2.size(); ++i)
        {
            sum2 += array2.at(i);
            set.insert(array2.at(i));
        }
        int diff = sum1 - sum2;
        vector<int> v;
        if(diff % 2 != 0) //如果两个数组之和的差为奇数，则返回[]
        {
            return v;
        }
        //在两个数组中找差值为half_diff的两个元素 即看 array1.at(i) - half_diff 是否存在于set中
        int half_diff = diff / 2;
        for(int i = 0; i < array1.size(); ++i)
        {
            if(set.find(array1.at(i) - half_diff) != set.end())
            {
                v.push_back(array1.at(i));
                v.push_back(array1.at(i) - half_diff);
                break;
            }
        }

        return v;
    }
};
