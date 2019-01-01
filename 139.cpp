/*
bpos��ʾ���ַ����Ƿ���Դӿ�ͷcut����ǰλ�á�
bpos[i]==true������ַ�����ͷ����i���ַ����������ں����cut��
���ַ���sǰ�����0���Ӷ�Ϊ��̬�滮���ó�ֵ��bpos[0]==true
*/
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n=s.size();
        vector<bool> dp(n+1,false);
        unordered_set<string> ss;
        for(auto &s:wordDict) 
            ss.insert(s);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>0;j--)
            {
                if(dp[j-1]==false) 
                    continue;
                if(ss.find(s.substr(j-1,i-j+1))!=ss.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
