class Solution 
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int sum = 0;
        int time = -1;
        for(int i=0;i<timeSeries.size();i++)
        {
            if(time < timeSeries[i])
            {
                time = timeSeries[i]+duration-1;
                sum += duration;
            }
            else
            {
                sum += (timeSeries[i]+duration-1-time);
                time = timeSeries[i]+duration-1;
            }
        }
        return sum;
    }
};
