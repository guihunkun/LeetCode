/*
class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> hmap;
        vector<int> res(nums1.size());
        
        for (int i = 0; i < nums2.size(); i++)
            hmap[nums2[i]] = i;
        
        for (int i = 0; i < nums1.size(); i++)
        {
            int ind = hmap[nums1[i]] + 1;
            while (ind < nums2.size() && nums2[ind] < nums1[i])
                ind++;
            if (ind == nums2.size())
                res[i] = -1;
            else
                res[i] = nums2[ind];
        }
        return res;
    }
};
*/
class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res(nums1.size());
        int index = 0;
        for(int i=0; i<nums1.size(); i++)
        {
            for(int j=0; j<nums2.size(); j++)//遍历2,找到与1相同的数就记录index
                if(nums1[i] == nums2[j])
                {
                    index = j;
                    break;
                }
            for(int k=index; k<nums2.size(); k++)
            {//判断2中右边第一个比1大的数
                if(nums2[k] > nums1[i]) 
                {
                    res[i]=nums2[k];
                    break;
                }
                else
                res[i]=-1;
            }
        }
        return res;
    }
};
