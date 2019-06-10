/*
class Solution 
{
public:

    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int left = 0, right = letters.size() - 1;
        int mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(letters[mid] == target)
                break;
            else if(letters[mid] < target)
                left = mid + 1;
            else 
                right = mid -1;
        }
        if(letters[mid] == target)
        {
            while(mid < letters.size() - 1 && letters[mid + 1] == letters[mid])
                mid++;
            if(mid == letters.size() - 1)
                return letters[0];
            else
                return letters[mid + 1];
        }
        else
        {
            if(left == letters.size())
                return letters[0];
            else
                return letters[left];
        }
    }
};
/*
如果target的元素在vector中，那么将会返回mid，而我们之后只需要返回mid+1这一位的元素，当然如果mid已经是vector中的最后一位了，我们需要返回vector的第一个元素。
如果target的元素不在vector中，那么first对应的就是刚好大于target元素的最小元素，如果first已经超出了vector，那么返回vector的第一个元素。
*/

class Solution 
{
public:

    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int left = 0;
        int right = letters.size() ;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return letters[left % letters.size()];
    }
};
