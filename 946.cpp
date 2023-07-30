class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n=pushed.size();
        if(pushed.size()!=popped.size())
            return false;
        stack<int> sta;
        int j=0;
        for(int i=0;i<n;i++)
        {
            sta.push(pushed[i]);
            while(!sta.empty() && j<n &&sta.top()==popped[j])
            {
                sta.pop();
                j++;
            }
        }
        return j==n;
    }
};

