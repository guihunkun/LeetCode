class MyStack 
{
public:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() 
    {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        int n = q.size();
        q.push(x);
        while(n > 0)
        {
            q.push(q.front());
            q.pop();
            n--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int n = q.front();
        q.pop();
        return n;
    }
    
    /** Get the top element. */
    int top() 
    {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        if(q.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
