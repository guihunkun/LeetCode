class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        int maxnum_Index = 0;
        for(int i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxnum_Index])
                maxnum_Index = i;
        for(int i = 0; i < nums.size(); i++)
            if(maxnum_Index != i && nums[maxnum_Index] < 2* nums[i])
                return -1;
        return maxnum_Index;
    }
};


