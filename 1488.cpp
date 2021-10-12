class Solution 
{
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> water;
        set<int> zero;

        for(int i = 0; i < rains.size(); i++) 
        {
            int r = rains[i];
            if(r == 0) {
                zero.insert(i);
                continue;
            }
            if(water.count(r) != 0) 
            {
                auto it = zero.lower_bound(water[r]);
                if (it == zero.end()) return {};
                ans[*it] = r;
                zero.erase(it);
            }
            water[r] = i;
            ans[i] = -1;
        }
        return ans;
    }
};

