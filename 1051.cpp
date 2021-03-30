class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        int res = 0;
        vector<int> record(101);
        for(int i = 0; i < heights.size(); i++)
            record[heights[i]]++;
        int j =0;
        for(int i =0; i < record.size() && j < heights.size(); i++)
        {
            if(record[i] != 0) {
                while(record[i] != 0) {
                    if(heights[j++]!=i) {
                        res++;
                    }
                    record[i]--;
                }
            }
        }
        return res;
    }
};
