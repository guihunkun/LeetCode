class Solution 
{
    long long mul(long long x,long long y)
    {
        return x*y;
    }
public://Õ∞≈≈–Ú
    int maximumGap(vector<int>& nums) 
    {
        if(nums.size()<2)
            return 0;
        int minnums=nums[0];
        int maxnums=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            minnums=min(minnums,nums[i]);
            maxnums=max(maxnums,nums[i]);
        }
        if(minnums==maxnums)
            return 0;
        int n=nums.size();
        vector<bool> empty(n+1,true);
        vector<int> nmax(n+1);
        vector<int> nmin(n+1);
        for(int i=0;i<n;i++)
        {
            int pos=mul((nums[i]-minnums),(n+1))/(maxnums-minnums);
            if(pos>n)
                pos=n;
            if(empty[pos])
            {
                empty[pos]=false;
                nmax[pos]=nums[i];
                nmin[pos]=nums[i];
            }
            else
            {
                nmax[pos]=max(nmax[pos],nums[i]);
                nmin[pos]=min(nmin[pos],nums[i]);
            }
        }
        int last=-1;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(!empty[i])
            {
                if(last<0)
                    last=nmax[i];
                else
                {
                    ans=max(ans,nmin[i]-last);
                    last=nmax[i];
                }
            }  
        }
        return ans;
    }
};
