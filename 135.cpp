class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        if(ratings.empty()) 
            return 0;
        int size = ratings.size();
        int candies = 1;
        int sum = 1;
        int max = 0;
        int downIndex = 0;
        for(int i=1;i<size;i++)
        {
            if(ratings[i]<ratings[i-1])
            {
                if(downIndex==0)
                {
                    // 记录上一个评分波峰峰值
                    max = candies;
                    // 记录评分开始下降的位置
                    downIndex=i;
                }
                candies=1;
                // 补发糖果
                sum+=i-downIndex;
                // 判断波峰是否需要补发糖果
                if(i-downIndex+1>=max)
                    sum+=1;
            }
            else if(ratings[i]>ratings[i-1])
            {
                downIndex = 0;
                candies+=1;
            } else {
                downIndex = 0;
                candies=1;
            }
            // 发糖果
            sum+=candies;
        }
        return sum;
    }
};
