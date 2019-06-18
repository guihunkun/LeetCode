class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> record;
        for(int weight : stones)
            record.push(weight);
        while(! record.empty())
        {
            if(record.size() == 1)
                return record.top();
            else
            {
                int max1 = record.top();
                record.pop();
                int max2 = record.top();
                record.pop();
                if(abs(max1 - max2) != 0)
                    record.push(max1 - max2);
            }
        }
        return 0;
    }
};
