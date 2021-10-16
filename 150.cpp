class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> stack;
        int size = tokens.size();

        for(int i = 0;i<size;i++){
            string str = tokens[i];
            int first;
            int second;

            if(str=="+")
            {
                 second = stack.top();stack.pop();
                 first = stack.top();stack.pop();
                stack.push(second+first);
            }else if(str=="-")
            {
                second = stack.top();stack.pop();
                first = stack.top();stack.pop();
                stack.push(first-second);
            }else if(str=="*")
            {
               second = stack.top();stack.pop();
               first = stack.top();stack.pop();
                stack.push(first*second); 
            }else if(str=="/")
            {
               second = stack.top();stack.pop();
                first = stack.top();stack.pop();
                stack.push(first/second); 
            }else
            {//为整数，解析并压栈
                int val = atoi(str.c_str());
                stack.push(val);
             }
        }
        return stack.top();
    }
};




