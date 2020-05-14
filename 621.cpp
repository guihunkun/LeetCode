class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
         vector<int> rec(26,0);
         for(char c : tasks)
         {
             rec[c-'A']++;
         }
         sort(rec.begin(), rec.end());
         int maxVal = rec[25]-1;
         int idle = maxVal*n;
         for(int i = 24; i >= 0 && rec[i] > 0; i--)
         {
            idle -= min(rec[i], maxVal);
         }
         return idle > 0 ? idle+tasks.size() : tasks.size();
    }
};
