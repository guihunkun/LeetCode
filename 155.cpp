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
        if(!s.empty() && p==min)
        {
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
����ջʱ��������Ԫ�ر���СֵС����ô����������Сֵ��ջ��Ȼ��Ԫ��ֵ������Сֵ�����µ���Сֵ��Ȼ�����������Ԫ����ջ���ڳ�ջʱ�����ջ��Ԫ������Сֵ��ȣ�˵��������һ��Ԫ����֮ǰpush����Сֵ����һ��������ջ�󣬽����֮ǰ����Сֵ��ֵ�����µ���Сֵ����ÿ��push��ȥ����Сֵ��������Ԫ�ص���Сֵ��
*/
