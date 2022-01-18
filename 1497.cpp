class Solution 
{
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int, int> mod;
        for(int num: arr) {
            ++mod[(num % k + k) % k];
        }
        for(auto [t, occ]: mod) 
        {
            if(t > 0 && (!mod.count(k - t) || mod[k - t] != occ)) {
                return false;
            }
        }
        return mod[0] % 2 == 0;
    }
};

