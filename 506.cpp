
class Solution 
{
public:
    struct Node 
    {
        int index;
        int score;
        Node(int i, int s) : index(i), score(s) {};
        bool operator < (const Node& other) const 
        {
            if (score == other.score) 
            {
                return index < other.index;
            }
            return score > other.score;
        }
    };
    string trans(int i) 
    {
        if (i == 0) 
            return "Gold Medal";
        if (i == 1) 
            return "Silver Medal";
        if (i == 2) 
            return "Bronze Medal";
        return to_string(i + 1);
    }
    vector<string> findRelativeRanks(vector<int>& nums) 
    {
        int N = nums.size();
        vector<Node> nodes;
        for (int i = 0; i < N; ++i) 
        {
            nodes.push_back(Node(i, nums[i]));
        }
        sort(nodes.begin(), nodes.end());
        vector<string> res(N);
        for (int i = 0; i < N; ++i) 
        {
            res[nodes[i].index] = trans(i);
        }
        return res;
    }
};
