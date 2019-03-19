#include <iostream>
using namespace std;
class time
{
public:
    time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}     //Ĭ�ϲ�����������ʼ�����캯��
    void display();
    time  & operator ++();    //ǰ����������
    time  & operator ++(int);   //������������
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
    return *this;  //this ָ����Ǹö���
}
time & time::operator ++(int)
{
    time c=*this;         //������ʱ����
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
    t2=t1++;         //��ȡt1��ֵ����t2��t1�ڽ�������1����
    cout<<"t1++ :"<<endl;
    t1.display();
    cout<<"t2 :"<<endl;
    t2.display();
    ++t1;
    cout<<"++t1 :"<<endl;
    t1.display();
    return 0;
}

