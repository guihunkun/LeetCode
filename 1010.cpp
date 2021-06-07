class Solution 
{
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int res = 0;
        vector<int> record(60, 0); // Õû³ý60ÓàÊý ³õÊ¼»¯Ä¬ÈÏÖµ0
        for(int i = 0; i < time.size(); i++) {
            record[time[i] % 60]++;
        }
        res += record[0] * (record[0] - 1) /2 + record[30] * (record[30] - 1) / 2;
        for(int i = 1; i < 30; i++)
            res += record[i] * record[60 - i];
        return res;
    }
};
