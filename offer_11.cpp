class Solution 
{
public:
    int minArray(vector<int>& numbers) 
    {
        int left = 0;
        int right = numbers.size()-1;
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(numbers[mid] < numbers[right])
            {
                right = mid;
            }
            else if(numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else
            {
                right -= 1;
            }
        }
        return numbers[left];
    }
};
