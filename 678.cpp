class Solution 
{
public:
    bool checkValidString(string s) 
    {
        stack<int> left, star; //�ֱ��¼�����ź�*���±�
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                left.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(!left.empty())    //��������������ƥ�������ţ�û�еĻ�ƥ��*
                    left.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;  //�����Ź��ֱ࣬�ӷ���False
            }
        }
        while(!left.empty() && !star.empty()) 
        {
            if(star.top() < left.top())  //������������ƥ����������*��λ�ã���*���ַ�����������ߣ���ʾ�޷�ת���������Ÿ�������ƥ�䣬���Է���False
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
