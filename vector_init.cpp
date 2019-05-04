#include"iostream"
#include"vector"
using namespace std;
int main()
{
//    vector<int> res1{1,2,3};
//    for(int i=0;i<res1.size();i++)
//        cout<<res1[i]<<" "<<endl;

//    cout<<"***************"<<endl;
//    int ary[]={1,2,3,4,5};
//    for(int & e : ary )
//        e*=10;
//    for(int e:ary)
//        cout<<e<<" ";
//    cout<<endl;
//    cout<<"***************"<<endl;
    cout<<"#矩阵初始化指定行(r)列(c)大小"<<endl;
    int r=3,c=4; 
	vector<vector<int> > res(r, vector<int>(c));
	for(int i = 0; i < r; i++) 
		for(int j = 0; j < c; j++)
			res[i][j]=i*j;
	for(int i = 0; i < r; i++) 
	{
		for(int j = 0; j < c; j++)
			cout<<res[i][j]<<"    ";
		cout<<endl;
	}
    return 0;
}
