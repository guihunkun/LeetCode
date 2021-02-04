class MinStack 
{
public:
    /** initialize your data structure here. */
    stack<int> _stack;
    int _min = INT_MAX;
    MinStack() 
    {    
    }
    
    void push(int x) 
    {
        if(_min >= x) {
            if(!_stack.empty()) {
                _stack.push(_min);
            }
            _min = x;
        }
        _stack.push(x);
    }
    
    void pop() 
    {
        if(_stack.empty())
            return;
        if(_stack.size() == 1)
            _min = INT_MAX;
        else if(_min == _stack.top()) {//下一个元素是下一个最小值
            _stack.pop();
            _min = _stack.top();
        }
        _stack.pop();
    }
    
    int top() 
    {
        return _stack.top();
    }
    
    int getMin() 
    {
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
