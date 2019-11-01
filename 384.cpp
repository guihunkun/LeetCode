class Solution 
{
private:
    vector<int> original, array;
public:
    Solution(vector<int>& nums) 
    {
        original = nums;
        array = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return original;    
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        next_permutation(array.begin(), array.end());
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
