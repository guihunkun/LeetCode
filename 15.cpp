
/*
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
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<vector<int> > vecTest;
    vector<int> vec_int;

    vec_int.push_back(0);
    vec_int.push_back(1);
    vec_int.push_back(2);
    vec_int.push_back(3);

    vecTest.push_back(vec_int);

    auto iter = vecTest.begin();
    for(int i = 0;i<vec_int.size();++i)
    {
        cout << (*iter)[i] << endl;
    }
    return 0;
}

