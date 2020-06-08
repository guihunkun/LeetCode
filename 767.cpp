class Solution 
{
public:
    string reorganizeString(string S) 
    {
        if(S.size() <= 1)
        {
            return S;
        }
        map<char, int> record;
        for(auto c : S)
        {
            record[c]++;
        }
        unsigned int L = (S.size()+1)/2;
        priority_queue<pair<int, char> > pq;
        for(auto m : record)
        {
            if(m.second > L)
            {
                return "";
            }
            else
            {
                pq.push({m.second, m.first});
            }
        }
        string res = "";
        while(pq.size() > 1)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            res.push_back(p1.second);
            res.push_back(p2.second);
            if(--p1.first > 0)
            {
                pq.push({p1.first, p1.second});
            }
            if(--p2.first > 0)
            {
                pq.push({p2.first, p2.second});
            }
        }
        if(pq.size() == 1)
        {
            auto p1 = pq.top();
            if(p1.first > 1)
            {
                return "";
            }
            else
            {
                res.push_back(p1.second);
                return res;
            }
        }
        else
        {
            return res;
        }
    }
};
