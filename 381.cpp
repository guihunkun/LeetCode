class RandomizedCollection 
{
public:
    unordered_map<int, unordered_set<int> > value_indices;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedCollection() 
    {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        bool res = value_indices.count(val) == 0;
        nums.push_back(val);
        value_indices[val].insert(nums.size() - 1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {
        if(value_indices.count(val) == 0) 
            return false;
        int tail = nums.back();
        if(tail == val) 
        {
            value_indices[val].erase(nums.size() - 1);
            nums.pop_back();
        } 
        else 
        {
            int ind = *value_indices[val].begin();
            nums[ind] = tail;
            value_indices[tail].erase(nums.size() - 1);
            value_indices[tail].insert(ind);
            value_indices[val].erase(ind);
            nums.pop_back();
        }
        if(value_indices[val].empty()) 
        {
            value_indices.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() 
    {
        int s = nums.size();
        int r = rand() % s;
        return nums[r];
    }
};
