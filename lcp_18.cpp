/*
class Solution 
{
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) 
    {
        const int mod = 1e9 + 7;
        int res = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int j = drinks.size()-1;
        for(int i = 0; i < staple.size() && staple[i] < x; i++)
        {
            while(j >= 0 && staple[i] + drinks[j] > x) {
                j--;
            }
            if(j == -1) {
                break;
            }
            res += j+1;
            res %= mod;
        }
        return res;
    }
};
*/
class Solution 
{
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) 
    {
        const int mod = 1e9 + 7;
        int res = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        auto upper = upper_bound(drinks.begin(), drinks.end(), x-staple[0]);
        int id = upper - drinks.begin();
        int j = min(id, (int)drinks.size()-1);
        for(int i = 0; i < staple.size() && staple[i] < x; i++)
        {
            while(j >= 0 && staple[i] + drinks[j] > x) {
                j--;
            }
            if(j == -1) {
                break;
            }
            res += j+1;
            res %= mod;
        }
        return res;
    }
};



