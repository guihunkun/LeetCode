class Solution 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        map<int, int>record;
        vector<int> res;
        for(int i = 0; i < arr1.size(); i++)
            record[arr1[i]]++;
        for(int i = 0; i < arr2.size(); i++)
        {
            while(record[arr2[i]] != 0)
            {
                res.push_back(arr2[i]);
                record[arr2[i]]--;
            }
        }
        sort(arr1.begin(), arr1.end());
        for(int i = 0; i < arr1.size(); i++)
        {
            if((record[arr1[i]] >= 1))
                res.push_back(arr1[i]);
        }
        return res;
    }
};
