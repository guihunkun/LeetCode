#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
using namespace std;
    int removeDuplicates(vector<int>& nums) 
    {
//        int j=0;
//        if(nums.size()<=1)
//            return 0;
//        for(int i=1;i<nums.size();i++)
//        {
//            if(nums[j]!=nums[i])
//                j++;
//            else
//            {
//                while(nums[j]==nums[i])
//                {
//                    if(i==nums.size())
//                        break;
//                    i++;
//                }
//                j++;
//                nums[j]=nums[i];
//            }
//
//
//        }
//        return j+1;
		if (nums.size() == 0)
            return 0;
        //判断无输入
        int number = 0;//标记计数
        for (int i=0; i < nums.size() ; i++) 
		{
            if ( nums[i] != nums[number] ) 
			{
                number++;
                nums[number] = nums[i];
            }
        }
        number+=1; //标记+1即为数字个数
        return number;

    } 
int main()
{
	int  v1[10] = {0,0,1,1,1,2,2,3,3,4};
	vector<int> nums;
	for(int i=1;i<10;i++)
		nums.push_back(v1[i]);
	int po=0;	
	po=removeDuplicates(nums);
	printf("%d\n",po);
	for(int i=0;i<nums.size();i++)
		printf("%d ",nums[i]); 
	return 0;
}
