class Solution 
{
public:
    vector<string> readBinaryWatch(int num) 
    {
        bitset<4> hour;
        bitset<6> minute;
        vector<string> times;
        
        backtrack(times,hour,minute,0,num);
        return times;
    }
private:
    void backtrack(vector<string> &times, bitset<4> hour, bitset<6> minute, int i, int num)
    {
        if(num == 0)
        {
            int hr = hour.to_ulong();
            int min = minute.to_ulong();
            if(hr < 12 && min < 60)
            {
                string time = to_string(hr) + ":";
                time += min>=10?to_string(min):"0"+ to_string(min);
                times.push_back(time);
            }
        }
        else if(i < 10) 
        {
            if(i < 4)
            {
                hour[i] = 0;
                backtrack(times,hour,minute,i+1,num);
                hour[i] = 1;
                backtrack(times,hour,minute,i+1,num-1);
            }
            else
            {
                minute[i-4] = 0;
                backtrack(times,hour,minute,i+1,num);
                minute[i-4] = 1;
                backtrack(times,hour,minute,i+1,num-1);
            }
        }
    }
};
