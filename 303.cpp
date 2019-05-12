
class NumArray 
{
private:
    vector<int> su;
public:
    
    NumArray(vector<int>& nums) 
    {
        int num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            num += nums[i];
            su.push_back(num);
        }
    }
    
    int sumRange(int i, int j) 
    {
        if (0 == i)
            return su[j];

        /*if (i < 0 || i >= su.size() || j < 0 || j >= su.size() || i > j)
        {
            return 0;
        }
        */
        return su[j] - su[i - 1];
    }
};




/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
