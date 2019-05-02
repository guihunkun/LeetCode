class Solution 
{
public:
    static bool compare(pair<char,int>a,pair<char,int>b) 
    {
        return a.second>b.second;
    }
    string frequencySort(string s) 
    {
        unordered_map<char,int> hashMap;
        vector<pair<char,int>> pairArray;
        string res = "";
        
        for (int i=0;i<s.size();i++) 
            hashMap[s[i]]++;
        for (pair<char,int> pair:hashMap) 
            pairArray.push_back(pair);
        
        sort(pairArray.begin(),pairArray.end(),compare);
        
        for (pair<char,int> pair:pairArray) 
            res.append(pair.second,pair.first);
        
        return res;        
    }
};
