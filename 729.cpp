class MyCalendar 
{
public:
    MyCalendar() 
    {
    }
    
    bool book(int start, int end) 
    {
        if(mp.size()==0) {
            mp[start]=end;
            return true;
        }
           
        for(auto iter=mp.begin();iter!=mp.end();iter++)
        {
            if((iter->second>=end&&iter->first<end)||(iter->second>start&&iter->first<=start)||(iter->first>=start&&iter->second<end))
                return false;
        }
        mp[start]=end;
        return true;
    }
private:
    map<int,int> mp;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
