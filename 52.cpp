class Solution 
{
public:
    int totalNQueens(int n) 
    {
        int count=0;
        backtrack(0,n,0,0,0,count);
        return count;
    }
    void backtrack(int r, int n, int col, int hill, int dale, int& count) 
    {
        if(r>=n) 
            count++;
        else
        {  
            for(int c=0;c<n;c++)
                //检查col,hill,dale特定位上的值
                //如(1&col>>c)==0，就是检查col第c个比特位是否==0
                //r表示行下标，c表示列下标，r+c与r-c的值均为常数，注意：r-c有可能小于0，所以要+n
                if((1&col>>c)==0&&(1&hill>>r+c)==0&&(1&dale>>r-c+n)==0)
                    //将col,hill,dale特定位的0置为1
                    //如col|1<<c，就是将col第c个比特位的0变为1
                    //由于参数传的是右值，所以递归返回之后会自动回溯
                    backtrack(r+1,n,col|1<<c,hill|1<<r+c,dale|1<<r-c+n,count);
        }
    }
};
