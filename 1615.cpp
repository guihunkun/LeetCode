//leetcode
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> edges(n);
        vector<int> indeg(n);
        for (const auto& road: roads) {
            edges[road[0]].insert(road[1]);
            edges[road[1]].insert(road[0]);
            ++indeg[road[0]];
            ++indeg[road[1]];
        }
        
        int first = -1, second = -2;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] > first) {
                second = first;
                first = indeg[i];
            }
            else if (indeg[i] > second) {
                second = indeg[i];
            }
        }

        vector<int> firstList, secondList;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == first) {
                firstList.push_back(i);
            }
            else if (indeg[i] == second) {
                secondList.push_back(i);
            }
        }

        if (firstList.size() == 1) {
            int u = firstList[0];
            for (int v: secondList) {
                if (!edges[u].count(v)) {
                    return first + second;
                }
            }
            return first + second - 1;
        }
        else {
            int m = roads.size();
            if (firstList.size() * (firstList.size() - 1) / 2 > m) {
                return first * 2;
            }
            for (int u: firstList) {
                for (int v: firstList) {
                    if (u != v && !edges[u].count(v)) {
                        return first * 2;
                    }
                }
            }
            return first * 2 - 1;
        }
    }
};


