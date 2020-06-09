class Solution 
{
public:
    double res[30][30][110];
    int X[8]{-2,-1,1,2,-2,-1,1,2};//8中走法
    int Y[8]{1,2,2,1,-1,-2,-2,-1};
    double steps(int N,int k,int r,int c)
    {
        if(k==0) 
            return 1.0;
        if(res[r][c][k]!=0) 
            return res[r][c][k];
        double st=0;
        for(int i=0;i<8;i++)
        {//遍历每种走法
            int n=r+X[i];
            int m=c+Y[i];
            if((n>=0&&n<N)&&(m>=0&&m<N))
            {//如果在棋盘内，递归调用,步数减一为 k-1
                st+=steps(N,k-1,n,m);
            }
        }
        res[r][c][k]=st/8.0;//返回在当前状态下马经过8中走法仍在棋盘的概率
        return st/8.0;
    }
    double knightProbability(int N, int K, int r, int c) 
    {
        memset(res,0,sizeof(res));
        double res=steps(N,K,r,c);
        return res;
    }
};
