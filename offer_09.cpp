class CQueue 
{
private:
    stack<int> st1,st2;
public:
    CQueue() 
    {

    }
    
    void appendTail(int value) 
    {
        st1.push(value);
    }
    
    int deleteHead() 
    {
        if(!st2.empty())
        {
            int tar = st2.top();
            st2.pop();
            return tar;
        }
        else
        {
            while(!st1.empty())
            {
                int num = st1.top();
                st1.pop();
                st2.push(num);
            }
            if(st2.empty())
            {
                return -1;
            }
            else
            {
                int num = st2.top();
                st2.pop();
                return num;
            }
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
