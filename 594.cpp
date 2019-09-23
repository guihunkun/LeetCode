class Solution 
{
public:
    int findLHS(vector<int>& nums) 
    {
        map<int, int>Mp;
        for(int i=0; i<nums.size(); i++) 
          Mp[nums[i]]+=1;
        int maxLen = 0;
        for(auto i:Mp)
        {
            if(Mp.find(i.first+1)!=Mp.end())
            {
                maxLen = max(maxLen, Mp[i.first]+Mp[i.first+1]);
            }
        }
        return maxLen;
    }
};

/*
class Solution 
{
public:
    int findLHS(vector<int>& nums) 
    {
        int res=0;
        map<int,int> m;
        for(auto num:nums) ++m[num];
        for(auto a:m)
        {
            if (m.count(a.first+1))
            {
                res=max(res,m[a.first]+m[a.first+1]);
            }
        }
        return res;
    }
};

*/
