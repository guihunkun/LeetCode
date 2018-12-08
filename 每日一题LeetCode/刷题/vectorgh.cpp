#include"iostream"
#include"vector" 
#include"string"
using namespace std;
	void quickSort(int s[], int l, int r)  
	{  
	    if (l< r)  
	    {        
	        int i = l, j = r, x = s[l];  
	        while (i < j)  
	        {  
	            while(i < j && s[j]>= x) // ���������ҵ�һ��С��x����  
	                j--;   
	            if(i < j)  
	                s[i++] = s[j];  
	            while(i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
	                i++;   
	            if(i < j)  
	                s[j--] = s[i];  
	        }  
	        s[i] = x;  
	        quickSort(s, l, i - 1); // �ݹ����  
	        quickSort(s, i + 1, r);  
	    }  
	}  
int main()
{
	int mm;
	string s;
	int nn[] = {1, 2, 3, 4, 5} ;
	vector<int> nums(nn,nn+5);
	int n=nums.size();
	int ss[n];
        for(int i=0;i<n;i++)
            ss[i]=nums[i];
    quickSort(ss,0,n);
    cin>>mm;
    cin>>s;
	cout<<mm<<endl; 
	cout<<s<<endl;   
	system("pause");    
	return 0;
}
