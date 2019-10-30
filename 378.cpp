/*
class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                q.push(matrix[i][j]);
                if(q.size()>k) 
                    q.pop();
            }

        }
        return q.top();
    }
};
*/
class Solution 
{
public:
/*
1.首先设置mid的初值为矩阵matrix，最后一个数和第一个数的平均值。 
2.统计矩阵中每一行小于mid值的个数之和。若该值小于8，记录当前mid，L = mid + 1，并更新mid；若该值大于8，R = mid - 1。 
3.重复上述搜索，直至L和R不满足L <= R,此时的mid值即为所求。
*/
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size(),l=matrix[0][0],r=matrix[n-1][n-1]+1;
        int mid=l;
        while(l<r)
        {
            mid=l+(r-l)/2;
            int cnt=0,cnt2=0;
            for(int i=0;i<n;i++)
            {
                auto &v=matrix[i];
                cnt+=lower_bound(v.begin(),v.end(),mid)-v.begin();
                cnt2+=upper_bound(v.begin(),v.end(),mid)-v.begin();
            }
            if(cnt<k&&cnt2>=k) 
                return mid;
            if(cnt<k) 
                l=mid+1;
            else 
                r=mid;
        }
        return mid;
    }
};


