#include"iostream"
#include"algorithm"
#include"string"
#include"ctime"
#include"cmath"
#include"cassert"

using namespace std;

template<typename Item>
class IndexMaxHeap
{
	private:
		Item* data;
		int* indexes; 
		int* reverse;
		int count;
		int capacity;
		void shiftup(int k)
		{
			while(k>1 && data[indexes[k/2]]<data[indexes[k]])
			{
				swap(indexes[k/2],indexes[k]);
				reverse[indexes[k/2]]=k/2;
				reverse[indexes[k]]=k;
				k/=2;
			}
		}
		void shiftdown(int k)
		{
			while(2*k<=count)
			{
				int j=2*k;
				if(j+1<=count && data[indexes[j+1]]>data[indexes[j]])
					j+=1;
				if(data[indexes[k]]>=data[indexes[j]])
					break;
				swap(indexes[k],indexes[j]);
				reverse[indexes[k]]=j;
				reverse[indexes[j]]=k;
				k=j;
			}
		}
		
	public:
		IndexMaxHeap(int capacity)
		{
			data=new Item[capacity+1];
			indexes=new int[capacity+1];
			reverse=new int[capacity];
			for(int i=0;i<capacity;i++)
				reverse[i]=0;
			count =0;
			this->capacity =capacity;
		}
		~IndexMaxHeap()
		{
			delete [] data;
			delete [] indexes;
			delete [] reverse;
		}
		int size()
		{
			return count;
		}
		bool isEmpty()
		{
			return count==0;
		}
		//传入的i对用户而言，是从0索引的 
		void insert(int i,Item item)
		{
			assert(count+1<=capacity);
			assert(i+1>=1 && i+1<=capacity);
			
			i+=1;
			data[i]=item;
			indexes[count+1]=i;
			reverse[i]=count+1;
			count++;
			shiftup(count);
		}
		Item extractMax()
		{
			assert(count>0);
			Item ret = data[indexes[1]];
			swap(indexes[1],indexes[count]);
			count--;
			shiftdown(1);
			return ret;
		}
		int extractMaxIndex()
		{
			assert(count>0);
			int ret = indexes[1]-1;
			swap(indexes[1],indexes[count]);
			reverse[indexes[1]]=1;
			reverse[indexes[count]]=0;
			count--;
			shiftdown(1);
			return ret;
		}
		bool contain(int i)
		{
			assert(i+1>=1 && i+1<=capacity);
			return reverse[i+1]!=0;
		}
		Item getItem(int i)
		{
			assert(contain(i));
			return data[i+1];	
		}
		void change(int i,Item newItem)
		{
			assert(contain(i));
			i+=1;
			data[i]=newItem;
//			for(int j=1;j<=count ;j++)
//			{
//				if(indexes[j]==i)
//				{
//					shiftup(j);
//					shiftdown(j);
//				}
//			}
			int j=reverse[i];
			shiftup(j);
			shiftdown(j);
		}	
}; 




int main()
{
	IndexMaxHeap<int> indexmaxheap=IndexMaxHeap<int>(100);
	//cout<<maxheap.size()<<endl;
	srand(time(NULL));
	for(int i=0;i<15;i++)
		indexmaxheap.insert(i,rand()%100) ;
	while(!indexmaxheap.isEmpty() )
		cout<<indexmaxheap.extractMax() <<" ";
	cout<<endl;
	return 0;
}
