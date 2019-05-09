class Solution 
{
public:
    vector<vector<int>> largeGroupPositions(string S) 
    {
        vector< vector<int>> res;
        int left = 0;
        for(int right = 0; right < S.size(); right++)
        {
            if(right == S.size()-1 || S[right] != S[right + 1])
            {
                if(right - left +1 >= 3)
                    res.push_back({left,right});
                left = right + 1;
            }
        }
        return res;
    }
};
