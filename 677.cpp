class MapSum 
{
private:
    map<string,int> record;

public:
    MapSum() 
    { 
    }

    void insert(string key, int val) 
    {
        record[key]=val;
    }

    int sum(string prefix) 
    {
        int result = 0;
        for(auto iter:record)
        {
            string str=iter.first;
            if(str.find(prefix)==0)//prefix是str的前缀
                result += iter.second;
        }
        return result;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
