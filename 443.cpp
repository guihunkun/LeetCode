class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size();
        int cur = 0; // 记录当前字符的索引，最后为压缩字符串的长度
        for(int i = 0; i < n; ) 
        {
            int j = i;
            while( j < n - 1 && chars[j] == chars[j+1]) 
            {// 查找字符连续相同的个数
                j++;
            }
            chars[cur++] = chars[i];// 将当前字符写入原字符串中
            if(i != j) 
            {
                string times = to_string(j - i + 1);// 字符连续相同的个数
                int tLen = times.length();
                for(int k = 0; k < tLen; k++) 
                {//把字符连续相同个数写入字符串，用来压缩
                    chars[cur++] = times[k];
                }
            }
            i = j + 1;//接着处理下一个字符
        }
        return cur;
    }
};
