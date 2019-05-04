/*
class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> diff;
        if(nums.size() <= 1)
            return 0;
        for(int i = 0; i < nums.size()-1; i++)
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j]-nums[i] == k)
                {
                    pair<int, int> pa;
                    pa=make_pair(nums[i], nums[j]);
                    diff.insert(pa);
                }
                if(nums[j]-nums[i] > k)
                    break;
            }
        return diff.size();
    }
};
*/
class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if(k < 0 || nums.size() <= 1)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0;
        int right = 1;
        while(right<nums.size())
        {
            int firNum = nums[left];
            int secNum = nums[right];
            if(secNum-firNum<k)
                right++;
            else if(secNum - firNum>k)
                left++;
            else
            {
                count++;
                while(left<nums.size() && nums[left]==firNum)
                {
                    left++;
                }
                while(right<nums.size() && nums[right]==secNum)
                {
                    right++;
                }

            }
            if(right==left)
                right++;
        }
        return count;
    }
};
