class Solution 
{
public:
    int calPoints(vector<string>& ops) 
    {
        int sum = 0;
        vector<int> elements(ops.size(),0);
        int j=0;
        for(int i=0; i<ops.size(); i++)
        {
            char c = ops[i][0];
            if(c == 'C')
            {
                j--; 
                elements[j] = 0;
            }
            else if(c == 'D')
            {
                elements[j] = elements[j-1]*2;
                j++;
            }
            else if(c == '+')
            {
                elements[j] = elements[j-1] + elements[j-2];
                j++;
            }
            else
            {
                elements[j] = stoi(ops[i]);
                j++;
            }
        }
        for(int i : elements)
            sum += i; 
        return sum;
    }
};
