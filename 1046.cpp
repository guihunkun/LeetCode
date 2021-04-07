class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        /*
         * 优先队列 : priority_queue
         * 对于基础类型 默认是大根堆(降序队列) : priority_queue<int> pq;
         * 小根堆(升序队列) : priority_queue<int, vector<int>, greater<int> > pq; 
         */
        priority_queue<int> record;
        for(int weight : stones)
            record.push(weight);
        while(! record.empty())
        {
            if(record.size() == 1)
                return record.top();
            else {
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
