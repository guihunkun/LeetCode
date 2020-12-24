class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        // ��ʼ����ϣӳ��
        unordered_map<char, vector<int>> ranking;
        for (char vid: votes[0]) {
            ranking[vid].resize(votes[0].size());
        }
        // ����ͳ��
        for (const string& vote: votes) {
            for (int i = 0; i < vote.size(); ++i) {
                ++ranking[vote[i]][i];
            }
        }
        
        // ȡ�����еļ�ֵ��
        using PCV = pair<char, vector<int>>;
        vector<PCV> result(ranking.begin(), ranking.end());
        // ����
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

