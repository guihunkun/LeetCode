class Solution 
{
    double findKth(vector<int>& nums1, vector<int>& nums2,int k)
    {
        if(nums1.size()>nums2.size())
            return findKth(nums2,nums1,k);
        if(nums1.size()==0)
            return nums2[k-1];
        if(nums2.size()==0)
            return nums1[k-1];
        if(k==1)
            return min(nums1[0],nums2[0]);
        int s1=nums1.size();
        int p1=min(s1,k/2);
        int p2=k-p1;
        if(nums1[p1-1]<nums2[p2-1])
        {
            vector<int> n1(nums1.begin()+p1,nums1.end());
            vector<int> n2(nums2.begin(),nums2.begin()+p2);
            return findKth(n1,n2,k-p1);
        }
        else
        {
            vector<int> n1(nums1.begin(),nums1.begin()+p1);
            vector<int> n2(nums2.begin()+p2,nums2.end());
            return findKth(n1,n2,k-p2);
        }
        
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int s1=nums1.size(),s2=nums2.size();
        int mid=(s1+s2)/2;
        if((s1+s2)%2==0)
            return (findKth(nums1,nums2,mid)+ findKth(nums1,nums2,mid+1))/2.0;
        else
            return findKth(nums1,nums2,mid+1);        
    }
};