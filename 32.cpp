class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int size = s.size();
       // 一个默认为-1的用于标记的数组
        vector<int>  m(size, -1);
        // 从 1 开始 向右 遍历每个字符。
        for(int i = 1; i < size; i++) 
        {
            // 跳过左括号
            if(s[i] == '(') 
            { 
                continue; 
            }
            // 向前遍历，跳过 已经成对 括号【标记为 0 或者 2】的位置
            // 找到 标记为 -1 且 字符为 左括号的地方，将左括号标记为0，右括号标记为2
            for(int j = i - 1; j >= 0; j--) 
            {
                if(m[j] < 0 &&  s[j] == '(') 
                { 
                    m[j] = 0; 
                    m[i] = 2; break;
                }
            }
        }
        // max为返回值， tmp记录当前匹配括号总和
        int max = 0, tmp = 0;
        // 获取连续的 0,2标记总和，并随时更新到max，如果被-1标记打断，则tmp重新开始计算新长度。
        for(auto i : m) 
        {
            if(i >= 0) 
            { 
                tmp += i; 
            }
            else
            {
                tmp = 0; 
            }
            max = (tmp > max) ? tmp : max;
        }
        return max;
    }
};
