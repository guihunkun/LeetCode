class Solution 
{
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n = chalk.size();
        if (chalk[0] > k) {
            return 0;
        }
        for (int i = 1; i < n; ++i) 
        {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k) {
                return i;
            }
        }

        k %= chalk.back();
        return upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    }
};

