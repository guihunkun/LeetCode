#include <iostream>
using namespace std;
class time
{
public:
    time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}     //默认参数，参数初始化表构造函数
    void display();
    time  & operator ++();    //前置自增运算
    time  & operator ++(int);   //后置自增运算
private:
    int hour,minute,second;
};
time  & time::operator ++()
{
    second++;
    if(second>=60)
    {
        second-=60;
        minute++;
        if(minute>=60)
        {
            minute-=60;
            hour++;
            hour=hour%24;
        }
    }
    return *this;  //this 指向的是该对象
}
time & time::operator ++(int)
{
    time c=*this;         //建立临时对象
    ++(*this);
    return c;
}
void time::display()
{
    cout<<"hour:"<<hour<<" minute:"<<minute<<" second:"<<second<<endl;
}
int main()
{
    time t1(12,59,59),t2;
    t2=t1++;         //先取t1的值赋给t2，t1在进行自增1运算
    cout<<"t1++ :"<<endl;
    t1.display();
    cout<<"t2 :"<<endl;
    t2.display();
    ++t1;
    cout<<"++t1 :"<<endl;
    t1.display();
    return 0;
}

