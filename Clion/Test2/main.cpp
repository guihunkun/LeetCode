
#include <iostream>
using namespace std;
class Base0{
public:
    int var0;
    void fun(){
        cout<<"Member of Base0"<<endl;
    }
};
class Base1: public Base0{
public:
    int var1;
};
class Base2: public Base0{
public:
    int var2;
};
class Derived:public Base1, public Base2{
public:
    int var;
    void fun(){
        cout<<"Member of Derived"<<endl;
    }
};

int main()
{
    Derived p;
    Derived *q=&p;
    p.Base1::var0=2;
    p.Base2::fun();
    q->Base2::var0=3;
    q->Base2::fun();
    return 0;
}

