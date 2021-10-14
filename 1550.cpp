class Solution 
{
public:
    bool isOdd(const int num)
    {
        return num%2 == 1;
    }
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(isOdd(arr[i])) {
                cnt++;
            } else {
                cnt = 0;
            }
            if(cnt == 3) {
                return true;
            }
        }
        return false;
    }
};


