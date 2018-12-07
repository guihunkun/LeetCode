#include<iostream.h>
#include"string"
#include"fstream"
#include<queue.h>
#include<stack.h>
/*      ȫ�ֱ���      */
const int INF = 100000000;
typedef pair<int, int> P;
char maze[10][11]; // ��ʾ�Թ����ַ���������
int N=10; 
int M=10;
int sx, sy; // �������
int gx, gy; // �յ�����
int d[10][10]; // ������λ�õ���̾��������
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() 
{
	queue<P> que;
	// �����е�λ�ö���ʼ��ΪINF
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			d[i][j] = INF;
		// ����������У�������һ�ص�ľ�������Ϊ0
		que.push(P(sx, sy));
		d[sx][sy] = 0;
		// ����ѭ��ֱ�����еĳ���Ϊ0
		while (que.size()) {
		// �Ӷ��е���ǰ��ȡ��Ԫ��
		P p = que.front(); que.pop();
		// ���ȡ����״̬�Ѿ����յ㣬���������
		if (p.first == gx && p.second == gy) 
			break;
		// �ĸ������ѭ��
		for (int i = 0; i < 4; i++) 
		{
			// �ƶ�֮���λ�ü�Ϊ(nx, ny)
			int nx = p.first + dx[i], ny = p.second + dy[i];
			// �ж��Ƿ�����ƶ��Լ��Ƿ��Ѿ����ʹ���d[nx][ny]!=INF��Ϊ�Ѿ����ʹ���
			if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' &&d[nx][ny] == INF) 
			{
				// �����ƶ��Ļ�������뵽���У����ҵ���λ�õľ���ȷ��Ϊ��p�ľ���+1
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}
void solve() 
{
	int res = bfs();
	printf("%d\n", res);
}
void main()
{
	FILE *fp1;
    fp1 = fopen("1.txt", "r");
    fscanf(fp1, "%s", &maze);
	solve();
	fclose(fp1);
}


