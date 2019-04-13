class Solution 
{
public:
    bool checkValidString(string s) 
    {
        stack<int> left, star; //分别记录左括号和*的下标
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                left.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(!left.empty())    //遇到右括号优先匹配左括号，没有的话匹配*
                    left.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;  //右括号过多，直接返回False
            }
        }
        while(!left.empty() && !star.empty()) 
        {
            if(star.top() < left.top())  //当所有右括号匹配结束，检查*号位置，当*在字符串左括号左边，表示无法转化成右括号跟左括号匹配，所以返回False
                return false;
            else
            {
                left.pop();
                star.pop();
            }
        }
        return left.empty();
    }
};
