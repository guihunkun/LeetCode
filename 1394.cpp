class Solution 
{
public:
    int findLucky(vector<int>& arr) 
    {
        int res = -1;
        map<int, int> rec;
        for(int i = 0; i < arr.size(); i++) {
            rec[arr[i]]++;
        }
        map<int, int>::iterator iter = rec.begin();
        for(; iter != rec.end(); iter++) 
        {
            if((*iter).first == (*iter).second) {
                res = max(res, (*iter).second);
            }
        }
        return res;
    }
};
