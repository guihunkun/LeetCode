class Solution 
{
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
    {
        int res = 0;
        for(int i = 0; i < arr.size()-2; i++)
        {
            for(int j = i+1; j < arr.size()-1; j++)
            {
                for(int k = j+1; k < arr.size(); k++)
                {
                    bool st1 = abs(arr[i]-arr[j]) <= a;
                    bool st2 = abs(arr[j]-arr[k]) <= b;
                    bool st3 = abs(arr[i]-arr[k]) <= c;
                    if(st1 && st2 && st3)
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
