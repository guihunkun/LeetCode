#include<iostream>
using namespace std;
int data[102][102],longetr[102][102];
int m,n;
int cal(int i,int j)
{
	int max = 0;
	if (longetr[i][j] > 0)
		//����õ��Ѿ������ֱ�ӷ���·�����ȣ��������еļ��������Ƕ�̬�滮��Խ֮��
		return longetr[i][j];
	if(j-1 >= 0 && data[i][j] > data[i][j-1] && max < cal(i,j-1))
		max = cal(i,j-1);//������
	if(j+1 < n && data[i][j] > data[i][j+1] && max < cal(i,j+1))
		max = cal(i,j+1);//������
	if(i-1 >= 0 && data[i][j] > data[i-1][j] && max < cal(i-1,j))
		max = cal(i-1,j);//������
	if(i+1 < m && data[i][j] > data[i+1][j] && max < cal(i+1,j))
		max = cal(i+1,j);//������
	return longetr[i][j] = max + 1;//�·�����������ĸ��ڵ��·����1��������·���������
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

