class StackOfPlates
{
private:
    vector<stack<int>> plates; // 盘子
    int capacity_per_stack;    // 每叠盘子的最大容量
public:
    StackOfPlates(int cap) 
    {
        capacity_per_stack = cap;
        plates.push_back(stack<int>());
    }
    
    void push(int val) 
    {
        if(capacity_per_stack == 0) 
        {
            return;
        }
        if(plates.size() == 0 || plates.back().size() >= capacity_per_stack) {
            plates.push_back(stack<int>());
        }
        plates.back().push(val);
    }
    
    int pop() 
    {
        if(capacity_per_stack == 0) 
        {
            return -1;
        }
        if(plates.size() && plates.back().size()) {
            int ret = plates.back().top();
            plates.back().pop();
            if(plates.back().size() == 0) {
                plates.pop_back();
            }
            return ret;
        }
        return -1;
    }
    
    int popAt(int index) 
    {
        if(capacity_per_stack == 0 || index >= plates.size() || plates[index].size() == 0) {
            return -1;
        }
        int ret = plates[index].top();
        plates[index].pop();
        if(plates[index].size() == 0) {
            plates.erase(plates.begin() + index);
        }
        return ret;
    }

};


/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
