
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        deque<int> deq;
        for(int i = 0; i != nums.size(); i++)
        {
            while(!deq.empty() && nums[deq.back()] <= nums[i]){
                deq.pop_back();
            }
            while(!deq.empty() && (deq.front() < i-k+1)) {
                deq.pop_front();
            }
            deq.push_back(i);
            if(i >= k-1) ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};

