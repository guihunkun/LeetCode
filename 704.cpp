class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==0)
            return -1;
        int start=0,end=nums.size()-1;
        while(start+1<end)
        {
            int mid =start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        if(nums[start]==target)
            return start;
        if(nums[end]==target)
            return end;
        return -1;
    }
};

/*
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==0)
            return -1;
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid =start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
};
*/
