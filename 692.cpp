class Solution 
{
public:
    static bool cmp(pair<int, string> x, pair<int, string> y)
    {
        if(x.first != y.first) 
            return x.first > y.first;
        else return 
            x.second < y.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> rec;
        vector<pair<int, string> > ans;
        for(auto word : words) 
            rec[word]++;
        for(auto item : rec){
            pair<int,string> tmp(item.second, item.first);
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end(), cmp);
        vector<string> res(k);
        for(int i=0;i<k;i++){
            res[i] = ans[i].second;
        }
        return res;
    }
};

