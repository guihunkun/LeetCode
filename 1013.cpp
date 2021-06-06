class Solution 
{
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int sum = 0;
        for(int i = 0; i < A.size(); i++)
            sum += A[i];
        if(sum % 3 != 0)
            return false;
        int left = 0, sum_left = 0;
        for(; left < A.size() - 2; left++)
        {
            sum_left += A[left];
            if(sum_left == sum / 3)
                break;
        }
        if(sum_left != sum / 3)
            return false;
        int right = A.size()-1, sum_right = 0;
        for(; right >= 1; right--) {
            sum_right += A[right];
            if(sum_right == sum / 3)
                break;
        }
        if(sum_right != sum / 3)
            return false;
        if(left > right)
            return false;
        int sum_mid = 0;
        for(int i = left + 1; i < right; i++)
            sum_mid += A[i];
        if(sum_mid != sum_left)
            return false;
        return true;
    }
};
