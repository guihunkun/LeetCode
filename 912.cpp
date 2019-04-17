class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        return mergeSort(nums, 0, nums.size()-1);
    }
    vector<int> mergeSort(vector<int>& arr, int l, int r)
    {
        // 对于小规模数组, 使用插入排序
        if( r - l <= 15 )
        {
            insertionSort(arr, l, r);
            return arr;
        }
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        return merge(arr, l, mid, r);
    }
    vector<int> merge(vector<int>& arr, int l, int mid, int r)
    {
        int aux[r-l+1];

        for( int i = l ; i <= r; i ++ )
            aux[i-l] = arr[i];

        // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
        int i = l, j = mid+1;
        for( int k = l ; k <= r; k ++ )
        {

            if( i > mid )
            {  // 如果左半部分元素已经全部处理完毕
                arr[k] = aux[j-l]; j ++;
            }
            else if( j > r )
            {  // 如果右半部分元素已经全部处理完毕
                arr[k] = aux[i-l]; i ++;
            }
            else if( aux[i-l] < aux[j-l] ) 
            {  // 左半部分所指元素 < 右半部分所指元素
                arr[k] = aux[i-l]; i ++;
            }
            else{  // 左半部分所指元素 >= 右半部分所指元素
                arr[k] = aux[j-l]; j ++;
            }
        }
        return arr;

    }
    vector<int> insertionSort(vector<int>& arr, int l, int r)
    {

        for( int i = l+1 ; i <= r ; i ++ ) 
        {

            int e = arr[i];
            int j;
            for (j = i; j > l && arr[j-1] > e; j--)
                arr[j] = arr[j-1];
            arr[j] = e;
        }
        return arr;
    }
};




/*
class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        return quickSort(nums, 0, nums.size()-1);
    }
    vector<int> quickSort(vector<int>& arr, int l, int r)
    {
        if( r - l <= 15 )
        {
            insertionSort(arr,l,r);
            return arr;
        }
        swap( arr[l], arr[rand()%(r-l+1)+l ] );
        int v = arr[l];
        int lt = l;     // arr[l+1...lt] < v
        int gt = r + 1; // arr[gt...r] > v
        int i = l+1;    // arr[lt+1...i) == v
        while( i < gt )
        {
            if( arr[i] < v )
            {
                swap( arr[i], arr[lt+1]);
                i ++;
                lt ++;
            }
            else if( arr[i] > v )
            {
                swap( arr[i], arr[gt-1]);
                gt --;
            }
            else
            { // arr[i] == v
                i ++;
            }
        }
        swap( arr[l] , arr[lt] );
        quickSort(arr, l, lt-1);
        quickSort(arr, gt, r);
        return arr;
    }
    vector<int> insertionSort(vector<int>& arr, int l, int r)
    {

        for( int i = l+1 ; i <= r ; i ++ ) 
        {

            int e = arr[i];
            int j;
            for (j = i; j > l && arr[j-1] > e; j--)
                arr[j] = arr[j-1];
            arr[j] = e;
        }
        return arr;
    }
};
*/




/*
class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        return quickSort(nums, 0, nums.size()-1);
    }
    vector<int> quickSort(vector<int>& arr, int l, int r)
    {
        if(l>=r)
            return arr;
        
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1 );
        quickSort(arr, p+1, r);
        return arr;
    }
    int partition(vector<int>& arr, int l, int r)
    {
        swap(arr[l],arr[rand()%(r-l+1)+l]);
        int v = arr[l];
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
};
*/
