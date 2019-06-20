class MyQueue 
{
public:
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stack<int> s2;
        while(! s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        s.push(x);
        while(! s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int t = s.top();
        s.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() 
    {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return s.empty();    
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
