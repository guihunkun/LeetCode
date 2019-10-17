class Solution 
{
public:
    static bool cmp(const int a, const int b)
    {
        if(a > b)
            return true;
        else
            return false;
    }
    int hIndex(vector<int>& citations) 
    {
        if(citations.size() == 0)
            return 0;
        sort(citations.begin(),citations.end(),cmp);
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] < i+1)
                return i;
        }
        return citations.size();
    }
};
