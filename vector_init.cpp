#include"iostream"
#include"vector"
using namespace std;
int main()
{
    vector<int> res{1,2,3};
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" "<<endl;

    cout<<"***************"<<endl;
    int ary[]={1,2,3,4,5};
    for(int & e : ary )
        e*=10;
    for(int e:ary)
        cout<<e<<" ";
    cout<<endl;
    cout<<"***************"<<endl;
    return 0;
}
