/* Method 1 : DFS + BFS
1. 找到第一个1的位置。
2. 使用 DFS 找出所有相连的1, 并将所有相连的1都放入到一个队列 queue 中，并且将该点的值改为2。
3. 使用 BFS 进行层序遍历，每遍历一层，结果 res 都增加1，当遇到1时，直接返回 res 即可。
*/
#if 1
class Solution 
{
public:
    int shortestBridge(vector<vector<int> >& A) 
    {
        int res = 0, n = A.size(), startX = -1, startY = -1;
        queue<int> q;
        vector<vector<int> > dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                if(A[i][j] == 0) 
                    continue;
                startX = i; startY = j;
                break;
            }
            if(startX != -1) 
                break;
        }
        helper(A, startX, startY, q);
        while(!q.empty()) 
        {
            for(int i = q.size(); i > 0; i--) 
            {
                int t = q.front(); 
                q.pop();
                for(int k = 0; k < dirs.size(); k++) 
                {
                    int x = t / n + dirs[k][0];
                    int y = t % n + dirs[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= n || A[x][y] == 2) 
                        continue;
                    if(A[x][y] == 1) 
                        return res;
                    A[x][y] = 2;
                    q.push(x * n + y);
                }
            }
            ++res;
        }
        return res;
    }
    void helper(vector<vector<int> >& A, int x, int y, queue<int>& q) 
    {
        int n = A.size();
        if(x < 0 || x >= n || y < 0 || y >= n || A[x][y] == 0 || A[x][y] == 2) 
            return;
        A[x][y] = 2;
        q.push(x * n + y);
        helper(A, x + 1, y, q);
        helper(A, x, y + 1, q);
        helper(A, x - 1, y, q);
        helper(A, x, y - 1, q);
    }
};

#endif


/* Method 2
1. 找到第一个1的位置。
2. 使用 BFS 找出所有相连的1, 并将所有相连的1都放入到一个队列 queue 中，并且将该点的值改为2。
3. 使用 BFS 进行层序遍历，每遍历一层，结果 res 都增加1，当遇到1时，直接返回 res 即可。

**注意 ：第一个 BFS 不需要是层序遍历的，而第二个 BFS 是必须层序遍历。
*/

#if 0
class Solution 
{
public:
    int shortestBridge(vector<vector<int>>& A) 
    {
        int res = 0, n = A.size();
        queue<int> que; // first BFS used
        queue<int> q;   // secod=nd BFS used

        vector<vector<int> > dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                if(A[i][j] == 0) 
                    continue;
                A[i][j] = 2;
                que.push(i * n + j);
                break;
            }
            if(!que.empty()) 
                break;
        }
        // first BFS
        while(!que.empty()) 
        {
            int t = que.front(); 
            que.pop();
            q.push(t);
            for(int k = 0; k < 4; k++) 
            {
                int x = t / n + dirs[k][0];
                int y = t % n + dirs[k][1];
                if(x < 0 || x >= n || y < 0 || y >= n || A[x][y] == 0 || A[x][y] == 2) 
                    continue;
                A[x][y] = 2;
                que.push(x * n + y);
            }
        }
        // second BFS
        while(!q.empty()) 
        {
            for(int i = q.size(); i > 0; i--) 
            {
                int t = q.front(); 
                q.pop();
                for(int k = 0; k < 4; k++) 
                {
                    int x = t / n + dirs[k][0];
                    int y = t % n + dirs[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= n || A[x][y] == 2) 
                        continue;
                    if(A[x][y] == 1) 
                        return res;
                    A[x][y] = 2;
                    q.push(x * n + y);
                }
            }
            ++res;
        }
        return res;
    }
};
#endif
