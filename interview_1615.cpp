class Solution 
{
public:
    vector<int> masterMind(string solution, string guess) 
    {
        map<char, int> rec;
        vector<int> res(2, 0);
        int count = 0;
        for(int i = 0; i < guess.size(); i++)
        {
            rec[guess[i]]++;
        }
        for(int i = 0; i < guess.size(); i++)
        {
            if(guess[i] == solution[i])
            {
                res[0]++;
            }
            if(rec[solution[i]])
            {
                count++;
                rec[solution[i]]--;
            }
        }
        res[1] = count - res[0];
        return res;
    }
};
