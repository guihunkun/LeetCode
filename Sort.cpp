#include"iostream"
#include"SortTestHelper.h"
#include"algorithm"
using namespace std;
template<typename T>



void selectionSort(T arr[],int n)  
{
	for(int i=0;i<n;i++)
	{
		int minIndex=i;
		for(int j=i+1;j<n;j++)
			if(arr[j]<arr[minIndex])
				minIndex=j;
		swap(arr[i],arr[minIndex]);
	}
}





template<typename T>
void insertionSort(T arr[],int n)    //sita(n.^2) 
{
	for(int i=1;i<n;i++)
	{
		T key=arr[i]; //Insert arr[i] into the sorted sequence arr[0,...i-1]
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}



template<typename T>
void bubbleSort(T arr[], int n)
{
    int i,j; T temp;
    for (i=0;i<n-1;i++)
        for (j=0;j<n-1-i;j++)
        if (arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
}




template<typename T>
void shellSort(T data,unsigned int len)
{
	if(len<=1||data==NULL)
  		return;
 	for(int div=len/2;div>=1;div=div/2)//定增量div，并不断减小
 	{
  		for(int i=0;i<div;++i)//分组成div组
  		{
   			for(int j=i;j<len-div;j+=div)//对每组进行插入排序
    			for(int k=j;k<len;k+=div)
     				if(data[j]>data[k])
      					swap(data[j],data[k]);//交换两个数的值
  		}
 	}
}



//将arr[l...mid]和arr[mid+1...r]两部分进行归并 
template<typename T>
void __merge(T arr[],int l,int mid,int r)
{
	T aux[r-l+1];
	for(int i=l;i<=r;i++)
		aux[i-l]=arr[i];
	int i=l,j=mid+1;
	for(int k=l;k<=r;k++)
	{
		if(i>mid)
		{
			arr[k]=aux[j-l];
			j++;
		}
		else if(j>r)
		{
			arr[k]=aux[i-l];
			i++;
		}
		else if(aux[i-l]<aux[j-l])
		{
			arr[k]=aux[i-l];
			i++;	
		}
		else
		{
			arr[k]=aux[j-l];
			j++;
		}	
	}
		
} 
//递归使用归并排序，对arr[l...r]的范围进行排序 
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	if(l>=r)
		return;
	int mid=l+(r-l)/2;
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r); 
	if(arr[mid]>arr[mid+1]) 
		__merge(arr,l,mid,r); 
}
template<typename T>
void mergeSort(T arr[],int n)
{
	__mergeSort(arr, 0, n-1);	
}




//对arr[l...r]部分进行partition操作
//返回p,使得arr[l...p-1]<arr[p];arr[p+1...r]>arr[p] 
template <typename T>
int __partition(T arr[], int l, int r)
{
	swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v )
		{
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

//对arr[l...r]部分进行快速排序 
template<typename T>
void __quickSort(T arr[],int l,int r)
{
	if(l>=r)
		return;
	int p=__partition(arr,l,r);
	__quickSort(arr,l,p-1);
	__quickSort(arr,p+1,r);
}
template<typename T>
void quickSort(T arr[],int n)
{
	srand(time(NULL));
	__quickSort(arr,0,n-1);	
}








int main()
{
	int n=15;
	int *arr=SortTestHelper::generateRandomArray(n,0,n);
	//sort(arr,arr+n);
	//selectionSort(arr,n);
	//insertionSort(arr,n);
	//bubbleSort(arr,n);
	//shellSort(arr,n);
	//mergeSort(arr,n);
	quickSort(arr,n);
	SortTestHelper::printArray(arr,n);
//	for(int i=0;i<n;i++)
//		cout<<arr[i]<<" ";
//	cout<<endl;
	delete [] arr; 
	return 0;
}
