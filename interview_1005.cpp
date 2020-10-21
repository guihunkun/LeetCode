class Solution 
{
public:
    int findString(vector<string>& words, string s) 
    {
        int l = 0, r = words.size() - 1;
        while(l < r) 
        {
            int mid = (l + r) >> 1;
            while(mid < r && words[mid] == "") 
                mid ++; //跳过空格
            if(mid == r) 
            {
                r = (l + r) >> 1; 
                continue;
            } //若是跳过空格，mid == r, 则二分后赋值给r
            if(words[mid] == s) 
                return mid; //标准二分法
            else if(words[mid] < s) 
                l = mid + 1;
            else 
                r = mid;
        }
        return words[r] == s ? r : -1;
    }
};
