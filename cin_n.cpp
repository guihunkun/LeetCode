#include"iostream"
#include"vector" 

using namespace std; 
	
int main()
{
 	int a,n,sum;
 	vector<int> cn;
 	sum=0;
 	cout<<"��������������"<<endl;
	scanf("%d",&n);  
	cout<<"������n������"<<endl;
 	for(int i=0;i<n;i++)
 	{
 		//scanf("%d ",&cn[i]);
 		cin>>a;
		cn.push_back(a);
 		sum+=cn.at(i);
	}
 		
 	cout<<"���ǵĺ��ǣ�"<<endl;
 	cout<<sum<<endl;
	return 0;
}
