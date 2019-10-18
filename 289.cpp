class Solution 
{
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        if(board.size() == 0)
            return;        
        int m = board.size();    // rows
        int n = board[0].size(); // columns
        
        // first iteration: mark states for each cell
        for(int i=0; i<m; i++) // rows
        {
            for(int j=0; j<n; j++) // columns
            {
                int cnt = 0;
                // count cell's live neighbors 3x3 matrix and set boundary
                for(int x= max(0, i-1); x <= min(m-1, i+1); x++)
                {
                    for(int y= max(0, j-1); y<= min(n-1, j+1); y++)
                    {
                        if(x == i && y == j) // skip itself
                            continue;
                        // only state 1 and 2: cell are live for previous state
                        if(board[x][y] == 1 || board[x][y] == 2)
                            cnt++;
                    }
                }
                
                if(board[i][j] == 0 && cnt == 3) // current is dead cell
                    board[i][j] = 3; // dead -> live
                else if(board[i][j] == 1 && (cnt < 2 || cnt > 3)) // current live cell
                    board[i][j] = 2; // live -> dead
            }
        }
        
        // second iteration: convert state back to dead or live
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                board[i][j] %= 2;
    }
};

/*
对于每一个cell， 可以建立 4种情况：

　　　　0 dead -> dead     没有变化

　　　　1 live -> live　　   没有变化

　　　　2 live -> dead　　从live 变为 dead

　　　　3 dead -> live　　从dead 变为live

　　　　对于情况0 和1， 因为没有变化，所以每个cell 的值 还是 0 和 1；

　　　　增加2种情况：如果是从 live 变为 dead， 就把值改成2； 如果是从 dead 变为 live， 就把值改成3。

　　　　那么对于每一个cell， 我们要查看的是它周围有几个live cell 来做判断，如果周围的cell 已经被改动过了，我们需要看的是它之前的状态。

　　　　那么我们看，红色的是初始的状态，蓝色的是改动过的状态，因为我们只需要查看live， 不管它有没有被改动过，我们只看红色部分就对了，因为我们要的是它初始的状态，那么只可能是1 和 2。所以我们只需要查看所有cell 是1 或者是 2的，来count 一共有几个live neighbors。
*/
