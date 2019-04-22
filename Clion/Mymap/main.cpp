#include"iostream"
#include"map"
using namespace std;
int main()
{
	map<int,int> myMap;
	if(myMap.find( 42 )==myMap.end())
		cout<<"Can not find"<<endl;
	else
		cout<<"** is in the map"<<endl;
	cout<<myMap[42]<<endl;
	if(myMap.find( 42 )==myMap.end())
		cout<<"Can not find"<<endl;
	else
		cout<<"** is in the map"<<endl;
	return 0;
}