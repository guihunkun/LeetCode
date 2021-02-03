class TripleInOne 
{
private:
    //这里是我们的私有数据，我们设置一个vector来存储数据
    //然后用一个数组来存储这个我们三个栈的指针的位置可以这么说
    vector<int> s;
    int stackSize;
    int spointer[3];
public:
    //这里进行初始化；
    TripleInOne(int stackSize) 
    {
        s = vector<int>(stackSize*3, 0);
        this->stackSize = stackSize; 
        spointer[0] = 0;
        spointer[1] = stackSize;
        spointer[2] = stackSize*2;
    }
    
    //然后将元素push进去的话我们首先看有没有溢出的
    void push(int stackNum, int value) 
    {
        if(spointer[stackNum] < (stackNum+1)*stackSize) {
            s[spointer[stackNum]++] = value;
        }
    }
    
    //这里的pop的话就看是否有元素让你pop出来，没有的话就返回-1
    int pop(int stackNum) 
    {
        int res = -1;
        if(spointer[stackNum] > (stackNum)*stackSize) {
            res = s[--spointer[stackNum]];
        }
        return res;
    }
    
    //peek的操作和上面的pop操作类似，不同的点就是我们不需要把指针往后退一步
    int peek(int stackNum) {
        int res = -1;
        if(spointer[stackNum] > (stackNum)*stackSize){
            res = s[spointer[stackNum]-1];
        }
        return res;
    }
    
    //看看是不是空的话我们就看每个栈的指针是不是在原来的初始位置上
    bool isEmpty(int stackNum) 
    {
        return spointer[stackNum] == stackNum*stackSize;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
