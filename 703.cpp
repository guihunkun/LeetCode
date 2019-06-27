class KthLargest 
{
private :
    priority_queue<int,vector<int>,greater<int>> q;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        int i;
        kth = k;
        for ( i = 0; i < k && i < nums.size(); i++ )
            q.push(nums[i]);
        
        while(i < nums.size()) 
        {
            if (nums[i] > q.top() ) 
            {
                q.pop();
                q.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) 
    {
        int k;
        if (q.empty() || q.size() < kth ) 
        {
            q.push(val);
        } 
        else 
        {
            k = q.top();
            if (val > k ) 
            {
                q.pop();
                q.push(val);
            }
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
