class TimeMap 
{
public:
    unordered_map<string, map<int, string>> cache;
public:
    /** Initialize your data structure here. */
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        cache[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) 
    {
        auto it = cache.find(key);
        if (it == cache.end()) 
            return "";
        auto iit = it->second.upper_bound(timestamp);
        if (iit == it->second.end()) 
            return it->second.rbegin()->second;
        else if (iit != it->second.begin())
        {
            iit--;
            return iit->second;
        } 
        else 
            return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
