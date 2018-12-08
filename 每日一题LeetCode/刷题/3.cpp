#include <iostream>
#include"stdio.h"
#include<vector>
using namespace std;
double find_kth(vector<int> a,int a_begin,vector<int> b,int b_begin,int k)
{
	int m=a.size();
	int n=b.size();
	if(a_begin>m-1)
		return b[b_begin+k-1];
	if(b_begin>n-1)
		return a[a_begin+k-1];
	if(k==1)
		return min(a[a_begin],b[b_begin]);
	int mid_a=INT_MAX;
	int mid_b=INT_MAX;
	if(a_begin+k/2-1<m)
		mid_a=a[a_begin+k/2-1];
	if(b_begin+k/2-1<n)
		mid_b=b[b_begin+k/2-1];
	if(mid_a<mid_b)
		return find_kth(a,a_begin+k/2,b,b_begin,k-k/2);
	return find_kth(a,a_begin,b,b_begin+k/2,k-k/2);
}
int main()
{
	
	vector<int> a;
	vector<int> b;
	for(int i=0;i<3;i++)
	{
		a.push_back(i);
		b.push_back(i+1);
	}	
	int m=a.size();
	int n=b.size();
	int total=m+n;
	if(total%2)
		cout<<find_kth(a,0,b,0,total/2+1)<<endl;
	else
		cout<<((find_kth(a,0,b,0,total/2)+find_kth(a,0,b,0,total/2+1))/2.0)<<endl;
	return 0;
 } 

