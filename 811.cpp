class Solution 
{
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        map<string, int> record;
        string s1, s2, s3;
        vector<string> ans;
        int cnt;
        for(auto it : cpdomains)
        {
            istringstream is(it);
            is >> cnt >> s1;
            record[s1] += cnt;

            s2 = s1.substr(s1.find('.') + 1);
            record[s2] += cnt;
            
            if(s2.find('.') != s2.npos) 
            {
                s3 = s2.substr(s2.find('.') + 1);
                record[s3] += cnt;
            }
        }
        for(auto kv : record) 
        {
            ans.push_back(to_string(kv.second) + ' ' + kv.first );
        }
        return ans;
    }
};
