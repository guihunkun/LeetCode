struct Node 
{
        int x;
        int y;
        int high;
        int step;
        Node(int x, int y, int high, int step) : x(x), y(y), high(high), step(step) {}
        bool operator<(const Node& node) const 
        {
            return this->high > node.high;
        }
};

class Solution {
public:
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>>& forest, int m, int n, Node& start, Node& end)
    {
        queue<Node> qu;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        qu.push(start);
        visited[start.x][start.y] = 1;

        while(!qu.empty()) {
            Node now = qu.front();
            qu.pop();

            if (now.x == end.x && now.y == end.y) {
                return now.step;
            }
            for (int i = 0; i < 4; i++) {
                int nx = now.x + d[i][0];
                int ny = now.y + d[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0 && visited[nx][ny] == 0) {
                    qu.push(Node(nx, ny, 0, now.step+1));
                    visited[nx][ny] = 1;
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int ans = 0;
        int m = forest.size();
        int n = forest[0].size();

        priority_queue<Node> qu;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    qu.push(Node(i, j, forest[i][j], 0));
                }
            }
        }
        Node last(0, 0, 0, 0);
        while (!qu.empty()) {
            Node now = qu.top();
            qu.pop();
            int step = bfs(forest, m, n, last, now);
            if (step == -1) return -1;
            last = now;
            ans += step;
            //forest[now.x][now.y] = 1;
        }
        return ans;
    }
};
