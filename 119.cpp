class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> cur,res;
        cur={1};
        res={1,1};
        if(rowIndex==0)
            return {1};
        if(rowIndex==1)
            return {1,1};
        for(int i=2;i<=rowIndex+1;i++)
        {
            for(int j=1;j<i-1;j++)
            {
                cur[j]=res[j-1]+res[j];
            }
            cur.push_back(1);
            res=cur;
        }
        return res;
    }
};
