#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
using namespace std;
    void twoSum(vector<int>& numbers, int target) 
    {
        int l,r;
        vector<int> dir(2,-1);
        l=0;
        r=numbers.size()-1;
        while(l<r)     //(r-l)>=1)
        {
            if(numbers[l]+numbers[r]==target)
            {
                dir[0]=l+1;
                dir[1]=r+1;
                cout<<l+1<<endl;
                break; 
            }
            else if(numbers[l]+numbers[r]<target)
                l++;
            else
                r--;
        }
    }
int main()
{
	int  v1[] = {1,2,3,4};
	vector<int> nums;
	for(int i=0;i<4;i++) {
		nums.push_back(v1[i]);
	}
	twoSum(nums,3); 
	return 0;
}

