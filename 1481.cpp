class Solution 
{
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2)
    {
        if(v1[0] == v2[0]) {
            return v1[1] < v2[1];
        } else {
            return v1[0] < v2[0];
        }
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        map<int, int> rec;
        for(auto num : arr) {
            rec[num]++;
        }
        auto iter = rec.begin();
        vector<vector<int> > vs;;
        for(; iter != rec.end(); iter++)
        {
            int key = iter->first;
            int val = iter->second;
            vector<int> tmp = {val, key};
            vs.push_back(tmp);
        }
        sort(vs.begin(), vs.end(), cmp);
        int count = 0;
        for(int i = 0; i < vs.size(); i++)
        {
            count += vs[i][0];
            if(count == k) {
                return vs.size()-i-1;
            } else if(count > k) {
                return vs.size()-i;
            }
        }
        return vs.size();
    }
};
