class DinnerPlates 
{
public:
    int cap;
    set<int> notFullStack;
    map<int, stack<int>> stackCont;
    DinnerPlates(int capacity) 
    {
        cap = capacity;
    }
    
    void push(int val) 
    {
        // 正常情况下 stackCont 为空时 notFullStack 也为空
        if(stackCont.size() == 0 ){
            // if(notFullStack.size() != 0) cout << "error in push fun" << endl;
            stackCont[0].push(val);
            if(stackCont[0].size() < cap) notFullStack.insert(0);

        } else if(stackCont.size() != 0 && notFullStack.size() == 0){
            // 逻辑不够严密
            int lastStackIndex = stackCont.rbegin()->first ;
            
            // 不需要 判断最后一个 stack 是否 满了
            stackCont[lastStackIndex + 1].push(val);
            
            if(stackCont[lastStackIndex + 1].size() < cap) notFullStack.insert(lastStackIndex + 1);

        } else if( stackCont.size() != 0 && notFullStack.size() != 0 ){
            int firstNotFullFromLeft = *notFullStack.begin();

            stackCont[firstNotFullFromLeft].push(val);

            if(stackCont[firstNotFullFromLeft].size() >= cap) notFullStack.erase(firstNotFullFromLeft);
        }
    }
    
    int pop() {
        if(stackCont.size() == 0) return -1;

        int lastStackIndex = stackCont.rbegin()->first ;
        int val = stackCont[lastStackIndex].top();
        
        stackCont[lastStackIndex].pop();
        int lastStackSize = stackCont[lastStackIndex].size();

        // 没有满的 stack
        notFullStack.insert(lastStackIndex);
        if(lastStackSize == 0) {
            stackCont.erase(lastStackIndex);
            notFullStack.erase(lastStackIndex);
        } 
        return val;
    }
    
    int popAtStack(int index) {
        if( stackCont.find(index) == stackCont.end() ) return -1;

        // 最大的栈 index
        int lastStackIndex = stackCont.rbegin()->first ;
        int val = stackCont[index].top();
        stackCont[index].pop();

        int thisStackSize = stackCont[index].size();

        notFullStack.insert(index);
        if(thisStackSize == 0) {
            stackCont.erase(index);

            if(lastStackIndex == index) notFullStack.erase(index);
        }

        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
