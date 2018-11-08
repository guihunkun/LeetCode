#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
using namespace std;
int findKthLargest(vector<int>& nums, int k) 
    {
        int key,j;
        for(int i=1;i<nums.size();i++)
        {
            key=nums[i];//insert nums[i] to the sorted nums[0...i-1]
            j=i-1;
            while(j>=0&&nums[j]<key)
            {
                nums[j+1]=nums[j];
                j--;
                
            }
            nums[j+1]=key;
        }
        return nums[k+1];
    }
int main()
{
	vector<int> arr;
	int cc[]={3,2,1,5,6,4};
	int po=0;
	for(int i=0;i<6;i++)
		arr.push_back(cc[i]);
	po=findKthLargest(arr,2);
	for(int i=0;i<6;i++)
		printf("%d ",arr[i]);
	printf("%d\n",po);
	return 0;
}
