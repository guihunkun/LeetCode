class Solution 
{
public:
    string rankTeams(vector<string>& votes)
    {
        int n = votes.size();
        // 初始化哈希映射
        unordered_map<char, vector<int>> ranking;
        for (char vid: votes[0]) {
            ranking[vid].resize(votes[0].size());
        }
        // 遍历统计
        for (const string& vote: votes) {
            for (int i = 0; i < vote.size(); ++i) {
                ++ranking[vote[i]][i];
            }
        }
        
        // 取出所有的键值对
        using PCV = pair<char, vector<int>>;
        vector<PCV> result(ranking.begin(), ranking.end());
        // 排序
        sort(result.begin(), result.end(), [](const PCV& l, const PCV& r) {
            return l.second > r.second || (l.second == r.second && l.first < r.first);
        });
        string ans;
        for (auto& [vid, rank]: result) {
            ans += vid;
        }
        return ans;
    }
};

