// Uncomment if you want to see the order of execution of operations

class LRUCache 
{
private:
    list<pair<int,int>> cacheDLL;
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    int maxSize;
    
public:
    LRUCache(int capacity) : maxSize(capacity) 
    {
        // std::cout << "Capacity = " << capacity << "\n\n";
    }
    
    int get(int key) {
        // std::cout << "Getting " << key << "\n";
        if (cache.find(key) == cache.end())     
            return -1;
        int val = (cache[key])->second;
        cacheDLL.erase(cache[key]);
        cacheDLL.push_front(make_pair(key,val));
        cache[key] = cacheDLL.begin();
        // std::cout << "Returned Value = " << val << "\n";
        return val;
    }
    
    void put(int key, int value) 
    {
        // std::cout << "Putting (key=" << key << " , value=" << value << ")\n";
        if (this->get(key) == value)   return;
        cacheDLL.push_front(make_pair(key,value));
        if (cache.find(key) != cache.end())     
            cacheDLL.erase(cache[key]);
        cache[key] = cacheDLL.begin();
        
        if (cache.size() > maxSize) 
        {
            int lastKey = (cacheDLL.rbegin())->first;
            // std::cout << "Evicting (key=" << lastKey << ", value=" << (cache[lastKey])->second << ")\n";
            cacheDLL.pop_back();
            cache.erase(lastKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

