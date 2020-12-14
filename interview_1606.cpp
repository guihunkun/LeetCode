#if 1
class Solution 
{
public:
    int smallestDifference(vector<int>& a, vector<int>& b) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long res = abs(a[0]-b[0]);
        for(int i = 0; i < a.size(); i++)
        {
            vector<int>::iterator low;
            low = lower_bound(b.begin(), b.end(), a[i]);
            int id = low - b.begin()-1;
            if(id < 0) {
                id = 0;
            }
            res = min(res, abs(long(b[id])-long(a[i])) );
            if(id < b.size()-1) {
                res = min(res, abs(long(b[id+1])-long(a[i])) );
            }
        }
        return res;
    }
};
#endif

#if 0
class Solution 
{
public:
    int smallestDifference(vector<int>& a, vector<int>& b) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        long res = INT_MAX;
        while (i < a.size() && j < b.size()) {
            res = min(res, abs(long(a[i])-long(b[j])));
            if(a[i] > b[j]) 
                ++j;
            else 
                ++i;
        }
        return res;
    }
};
#endif
