/*
class MinStack {
public:
    // initialize your data structure here. 
    stack<int> sm;
    stack<int> s;
    void push(int x) 
    {
        s.push(x);
        if(sm.empty() || (!sm.empty() && sm.top() >= x)) 
            sm.push(x);
    }

    void pop()
    {
        if(s.top() == sm.top()) sm.pop();
        s.pop();
    }

    int top() 
    {
        return s.top();
    }

    int getMin()
    {
        return sm.top();
    }
};
*/
    
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int min;
    void push(int x) 
    {
        if(s.empty())
        {
            s.push(x);
            min=x;
        }
        else
        {
            if(x<=min)
            {
                s.push(min);
                min=x;
            }
            s.push(x);
        }
    }
    void pop()
    {
        if(s.empty())
            return ;
        int p=s.top();
        s.pop();
        if(!s.empty() && p==min) {
            min=s.top();
            s.pop();
        }
    }

    int top() 
    {
        return s.top();
    }

    int getMin()
    {
        return min;
    }
};

/*
在入栈时，如果这个元素比最小值小，那么，我们让最小值入栈，然后将元素值赋给最小值，即新的最小值，然后正常将这个元素入栈；在出栈时，如果栈顶元素与最小值相等，说明他的下一个元素是之前push的最小值（上一个），出栈后，将这个之前的最小值赋值给最新的最小值。（每次push进去的最小值都是下面元素的最小值）
*/
