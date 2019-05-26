#include"iostream"
#include"string"
using namespace std;
int main()
{
	cout<<"*************** string 转 int ***************"<<endl;  //  to_string()
	string pi = "pi is " + to_string(3.1415926);
    string perfect = to_string(1+2+4+7+14) + " is a perfect number";
    cout << pi << endl;
  	cout << perfect << endl;

	cout<<"*************** int 转 string ***************"<<endl;  //采用标准库中atoi函数,对于其他类型也都有相应的标准库函数，比如浮点型atof(),long型atol()等等
	string str = "123";
	int n = atoi(str.c_str());
	cout<<n<<endl;
	return 0;
}
/*
 to_string()函数的实现:

#include<iostream>
#include<string>
using namespace std;
#define max 100
string to_String(int n)
{
    int m = n;
    char s[max];
    char ss[max];
    int i=0,j=0;
    if (n < 0)// 处理负数
    {
        m = 0 - m;
        j = 1;
        ss[0] = '-';
    }
    while (m>0)
    {
        s[i++] = m % 10 + '0';
        m /= 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
        ss[j++] = s[i--];
    }
    ss[j] = '\0';
    return ss;
}

int main()
{
    cout << "请输入整数:";
    int m;
    cin >> m;
    string s = to_String(m) + "abc";
    cout << s << endl;
    system("pause");
    return 0;
}

 */

/*
 atoi()函数的源码实现:

特殊情况：
1--指针为NULL
2--空字符处理
3--正号与负号的处理
4--溢出处理
5--如果遇到异常字符怎么处理


#include<iostream>
enum ret { kvalid=0,kinvalid };    // 是否有非法输入的标记
int status = kvalid;
long long Strtointcode(const char* digit, bool minus)
{
    long long num = 0;
    while (*digit != '\0')
    {
        if (*digit >= '0'&&*digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag*(*digit - '0');
            if ((!minus&&num > 0x7FFFFFFF) ||( minus&&num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }
    if (*digit == '\0')
        status = kvalid;
    return num;
}
int Strtoint(const char* str)
{
    status = kinvalid;
    long long num = 0;
    if (str != NULL&&*str != '\0')
    {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            str++;
            minus = true;
        }
        if (*str != '\0')
            num = Strtointcode(str, minus);

    }
    return (int)num;
}

int main()
{
    char arr[20];
    int ret = 0;
    printf("请输入您要转化的字符串：\n");
    scanf("%s", arr);
    ret = Strtoint(arr);
    if (kvalid == status)
    {
        printf("%d\n", ret);
    }
    else
    {
        printf("输入非法\n");
        printf("%d\n", ret);
    }
    system("pause");
    return 0;
}


 */
