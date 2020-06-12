/*
class Solution 
{
public:
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        int res = 0, j;
        for(int i = 0; i < words.size(); i++)
        {
            int index = -1;
            for(j = 0; j < words[i].size(); j++)
            {
                index = findWord(S, words[i][j], index+1);
                if(index == -1)
                    break;
            }
            if(j == words[i].size())
                res++;
        }
        return res;
    }
    int findWord(string& S, char c, int index)
    {
        for(int i = index; i < S.size(); i++)
        {
            if(S[i] == c)
            {
                return i;
            }
        }
        return -1;
    }
};
*/
class Solution 
{
public:
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        int res = 0, j;
        for (int i = 0; i < words.size(); i ++) 
        {
            int position = -1;
            for (j = 0; j < words[i].size(); j ++) 
            {
                position = S.find_first_of(words[i][j], position + 1); 
                // 从下标position + 1开始遍历
                if (position == -1) 
                    break;  //若未找到弹出
            }
            if (j == words[i].length()) 
                res ++; 
            //表示str已全部被遍历了，则为其子串
        }
        return res;
    }
};
