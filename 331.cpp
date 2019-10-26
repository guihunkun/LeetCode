class Solution 
{
    
/*
一颗空树应该有1个‘#’，在此基础上每增加一个非空节点时'#'的数量+1。

扫描一遍输入，初始cnt=1，碰到'#'时cnt--, 否则cnt++, 在扫描到结束之前如果cnt==0那么返回false。扫描一遍后如果cnt==0那么返回true，否则返回false
*/
public:
    bool isValidSerialization(string preorder) 
    {
        int n = preorder.size();
        if(preorder[n-1] != '#')
            return false;
        vector<string> record;
        int pos = -1;
        for(int i = 0; i < n; i++)
        {
            if(preorder[i] == ',')
            {
                record.push_back(preorder.substr(pos + 1, i - pos - 1));
                pos = i;
            }
        }
        record.push_back("#");
        int cnt = 1;
        for(int i = 0; i < record.size(); i++)
        {
            if(cnt <= 0)
                return false;
            if(record[i] == "#")
                cnt--;
            else
                cnt++;
        }
        return cnt == 0;
    }
};
