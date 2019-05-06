class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        int po1 = INT_MIN, po2 = INT_MIN, po3 = INT_MIN, ne1 = INT_MAX, ne2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= ne1)  // nums[i] <= ne1 < ne2
            {
                ne2 = ne1;
                ne1 = nums[i];
            }
            else if(nums[i] <= ne2) //  ne1 < nums[i] <= ne2 //其实最后只需判断是否小于ne2
                ne2 = nums[i];
            if(nums[i] >= po1)  //  nums[i] >= po1 > po2 > po3
            {
                po3 = po2;
                po2 = po1;
                po1 = nums[i];
            }
            else if(nums[i] >= po2)//   po1 > nums[i] >= po2 > po3
            {
                po3 = po2;
                po2 = nums[i];
            }
            else if(nums[i] >= po3)//   po1 > po2 > nums[i] >= po3  //其实最后只需判断是否大于po3
                po3 = nums[i];
        }
        return max(ne1*ne2*po1, po1*po2*po3);
    }
};
