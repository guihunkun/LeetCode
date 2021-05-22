class Solution 
{
public:
    int maxNumberOfBalloons(string text) 
    {
        map<int, int> rec;
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == 'a')
                rec[0]++;
            if(text[i] == 'b')
                rec[1]++;
            if(text[i] == 'n')
                rec[2]++;
            if(text[i] == 'l')
                rec[3]++;
            if(text[i] == 'o')
                rec[4]++;
        }
        int n1 = min(rec[0], min(rec[1], rec[2]));
        int n2 = min(rec[3], rec[4])/2;
        return min(n1,n2);
    }
};

