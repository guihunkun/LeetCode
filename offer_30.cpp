class MinStack 
{
private:
    stack<int> data;
    stack<int> minNum;

public:
    /** initialize your data structure here. */
    MinStack() 
    {
    }
    
    void push(int x) 
    {
		data.push(x);
		if(minNum.size() == 0) 
            minNum.push(x);
		else
		{
			if(x < minNum.top())
                minNum.push(x);
			else 
                minNum.push(minNum.top());
		}
    }
    
    void pop() 
    {
		if(data.size() == 0) 
            return;
		data.pop();
		minNum.pop();
    }
    
    int top() 
    {
        return data.top();
    }
    
    int min() 
    {
        return minNum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
