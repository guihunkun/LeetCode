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
���target��Ԫ����vector�У���ô���᷵��mid��������֮��ֻ��Ҫ����mid+1��һλ��Ԫ�أ���Ȼ���mid�Ѿ���vector�е����һλ�ˣ�������Ҫ����vector�ĵ�һ��Ԫ�ء�
���target��Ԫ�ز���vector�У���ôfirst��Ӧ�ľ��Ǹպô���targetԪ�ص���СԪ�أ����first�Ѿ�������vector����ô����vector�ĵ�һ��Ԫ�ء�
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
