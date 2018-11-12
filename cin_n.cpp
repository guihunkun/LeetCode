#include"iostream"
#include"vector" 

using namespace std; 
	
int main()
{
 	int a,n,sum;
 	vector<int> cn;
 	sum=0;
 	cout<<"请输入整数个数"<<endl;
	scanf("%d",&n);  
	cout<<"请输入n个整数"<<endl;
 	for(int i=0;i<n;i++)
 	{
 		//scanf("%d ",&cn[i]);
 		cin>>a;
		cn.push_back(a);
 		sum+=cn.at(i);
	}
 		
 	cout<<"他们的和是："<<endl;
 	cout<<sum<<endl;
	return 0;
}
