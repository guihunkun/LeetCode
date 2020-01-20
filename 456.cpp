class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        if(nums.size() < 3)
            return false;
        stack<int> st;
        vector<int> minrec(nums.size(), 0);
        minrec[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            minrec[i] = min(minrec[i-1], nums[i]);
        }
        for(int j = nums.size() -1; j >= 0; j--)
        {
            if(nums[j] > minrec[j])
            {
                while(!st.empty() && st.top() <= minrec[j])
                    st.pop();
                if(!st.empty() && st.top() < nums[j])
                    return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};
