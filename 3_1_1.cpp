#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
using namespace std;
int binarySearch(vector<int> ar,int n,int target)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int mid =l+(r-l)/2;    //·ÀÖ¹£¨l+r£©Òç³ö    //(l+r)/2;
		if(ar[mid]==target)
			return mid;
		if(target>ar[mid])
			l=mid+1;
		else 
			r=mid-1;
	}
	return -1;
}
int main()
{
	vector<int> arr;
	int N=100;
	int po=0;
	for(int i=0;i<N;i++)
		arr.push_back(i+10);
	po=binarySearch(arr,arr.size(),34);
	printf("%d\n",po);
	return 0;
}
