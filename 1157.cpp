class MajorityChecker 
{
    int n,N,s,a[20005],b[205][20005],d[205];
    map<int,int> m;
public:
    MajorityChecker(vector<int>& arr) 
    {
        n=arr.size();
        N=0;
        for(int i=0;i<n;i++)m[a[i]=arr[i]]++;
        s=sqrt(n*2);
        for(auto i:m)if(i.second>s>>1)
        {
            b[++N][0]=0;
            d[N]=i.first;
            for(int j=0;j<n;j++)b[N][j+1]=b[N][j]+(a[j]==d[N]);
        }
    }
    
    int query(int left, int right, int threshold) 
    {
        int i,j,k;
        if(right-left<=s)
        {
            j=k=0;
            for(i=left;i<=right;i++)if(a[i]==j)k++;
            else if(k)k--;
            else
            {
                j=a[i];
                k=1;
            }
            for(i=left,k=0;i<=right;i++)if(a[i]==j)k++;
            if(k<threshold)j=-1;
            return j;
        }
        for(i=1;i<=N;i++)if(b[i][right+1]-b[i][left]>=threshold)return d[i];
        return -1;
    }
};
