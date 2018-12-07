#include<iostream>
using namespace std;
int data[102][102],longetr[102][102];
int m,n;
int cal(int i,int j)
{
	int max = 0;
	if (longetr[i][j] > 0)
		//如果该点已经计算过直接返回路径长度，保存已有的计算结果这是动态规划优越之处
		return longetr[i][j];
	if(j-1 >= 0 && data[i][j] > data[i][j-1] && max < cal(i,j-1))
		max = cal(i,j-1);//向左走
	if(j+1 < n && data[i][j] > data[i][j+1] && max < cal(i,j+1))
		max = cal(i,j+1);//向右走
	if(i-1 >= 0 && data[i][j] > data[i-1][j] && max < cal(i-1,j))
		max = cal(i-1,j);//向上走
	if(i+1 < m && data[i][j] > data[i+1][j] && max < cal(i+1,j))
		max = cal(i+1,j);//向下走
	return longetr[i][j] = max + 1;//最长路径就是相邻四个节点最长路径加1所得四条路径中最长那条
}
int main()
{
	int i,j;
	cin>>m>>n;
	int maxway = 0;
	for ( i=0;i<m;i++)
		for( j=0;j<n;j++)
		{
			cin>>data[i][j];
			longetr[i][j] = 0;
		}
	for ( i=0;i<m;i++)
		for( j=0;j<n;j++)
		{
			longetr[i][j] = cal(i,j);
		}
	for ( i=0;i<m;i++)
		for( j=0;j<n;j++)
		{
			if(maxway < longetr[i][j])
				maxway = longetr[i][j];
		}
	cout<<maxway<<endl;
	return 0;
}

