class Solution 
{
public:
    int get_max(vector<int> &v)
    {
        int res = INT_MIN;
        for(auto x : v)
            res = max(res,x);   
        return res;
    }
    int get_min(vector<int> &v)
    {
        int res = INT_MAX;
        for(auto x : v)
            res = min(res,x);
        
        return res;
    }
    int maxValueAfterReverse(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        for(int i=0;i<n-1;i++)
            res += abs(nums[i] - nums[i + 1]);
        
        int maxv = 0;

        for(int i=0;i<n;i++)
        {
            if(i != n - 1)
                maxv = max(maxv,abs(nums[0] - nums[i + 1]) - 
                                abs(nums[i] - nums[i + 1])); // 左端点为0右端点为i
            if(i != 0)
                maxv = max(maxv,abs(nums[n - 1] - nums[i - 1]) -
                                abs(nums[i] - nums[i - 1])); // 右端点为n-1,左端点为i
        }

        int mx[4] = {1,1,-1,-1};
        int my[4] = {1,-1,1,-1};
        
        for(int i=0;i<4;i++) // 枚举四种情况
        {
            vector<int> v1,v2;
            for(int j=0;j<n-1;j++)
            {
                int a = mx[i] * nums[j];
                int b = my[i] * nums[j + 1];
                int cur = abs(nums[j] - nums[j + 1]);
                v1.push_back(a + b - cur);
                v2.push_back(a + b + cur);
            }
            int a = get_max(v1);
            int b = get_min(v2);
            maxv = max(maxv,a - b);
        }

        return res + maxv;
    }
};


