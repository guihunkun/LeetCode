#include"iostream"
#include"string"
using namespace std;
int main()
{
	cout<<"*************** string ת int ***************"<<endl;  //  to_string()
	string pi = "pi is " + to_string(3.1415926);
    string perfect = to_string(1+2+4+7+14) + " is a perfect number";
    cout << pi << endl;
  	cout << perfect << endl;

	cout<<"*************** int ת string ***************"<<endl;  //���ñ�׼����atoi����,������������Ҳ������Ӧ�ı�׼�⺯�������縡����atof(),long��atol()�ȵ�
	string str = "123";
	int n = atoi(str.c_str());
	cout<<n<<endl;
	return 0;
}
/*
 to_string()������ʵ��:

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
    if (n < 0)// ������
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
    cout << "����������:";
    int m;
    cin >> m;
    string s = to_String(m) + "abc";
    cout << s << endl;
    system("pause");
    return 0;
}

 */

/*
 atoi()������Դ��ʵ��:

���������
1--ָ��ΪNULL
2--���ַ�����
3--�����븺�ŵĴ���
4--�������
5--��������쳣�ַ���ô����


#include<iostream>
enum ret { kvalid=0,kinvalid };    // �Ƿ��зǷ�����ı��
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
    printf("��������Ҫת�����ַ�����\n");
    scanf("%s", arr);
    ret = Strtoint(arr);
    if (kvalid == status)
    {
        printf("%d\n", ret);
    }
    else
    {
        printf("����Ƿ�\n");
        printf("%d\n", ret);
    }
    system("pause");
    return 0;
}


 */
