class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> res;
        map<string, int> record;
        for(int i = 0; i < list1.size(); i++)
            record[list1[i]] = i + 1;
        int max_sum_index = list1.size() + list2.size(); 
        for(int i = 0; i < list2.size(); i++)
        {
            if(record[list2[i]] > 0)
            {
                int sum_index = i + record[list2[i]] - 1;
                if(sum_index < max_sum_index)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    max_sum_index = sum_index;
                }
                else if(sum_index == max_sum_index)
                    res.push_back(list2[i]);
            }
        }
        return res;
    }
};
