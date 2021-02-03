class TripleInOne 
{
private:
    //���������ǵ�˽�����ݣ���������һ��vector���洢����
    //Ȼ����һ���������洢�����������ջ��ָ���λ�ÿ�����ô˵
    vector<int> s;
    int stackSize;
    int spointer[3];
public:
    //������г�ʼ����
    TripleInOne(int stackSize) 
    {
        s = vector<int>(stackSize*3, 0);
        this->stackSize = stackSize; 
        spointer[0] = 0;
        spointer[1] = stackSize;
        spointer[2] = stackSize*2;
    }
    
    //Ȼ��Ԫ��push��ȥ�Ļ��������ȿ���û�������
    void push(int stackNum, int value) 
    {
        if(spointer[stackNum] < (stackNum+1)*stackSize) {
            s[spointer[stackNum]++] = value;
        }
    }
    
    //�����pop�Ļ��Ϳ��Ƿ���Ԫ������pop������û�еĻ��ͷ���-1
    int pop(int stackNum) 
    {
        int res = -1;
        if(spointer[stackNum] > (stackNum)*stackSize) {
            res = s[--spointer[stackNum]];
        }
        return res;
    }
    
    //peek�Ĳ����������pop�������ƣ���ͬ�ĵ�������ǲ���Ҫ��ָ��������һ��
    int peek(int stackNum) {
        int res = -1;
        if(spointer[stackNum] > (stackNum)*stackSize){
            res = s[spointer[stackNum]-1];
        }
        return res;
    }
    
    //�����ǲ��ǿյĻ����ǾͿ�ÿ��ջ��ָ���ǲ�����ԭ���ĳ�ʼλ����
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
