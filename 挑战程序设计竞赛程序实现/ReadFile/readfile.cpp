#include<iostream>
#include"string"
#include"fstream"
using namespace std;
/*      全局变量      */
int N=10, M=12;
char field[10][12]; 
/*      问题求解函数      */
void solve() 
{
	printf("%s\n",field);

}
void main()
{
	FILE *fp1;
    fp1 = fopen("1.txt", "r");
    fscanf(fp1, "%s", &field);
	solve();
	fclose(fp1);
}

