class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board)
    {
        const int N = 8;
        pair<int, int> pos;
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < N; ++j) 
            {
                if (board[i][j] == 'R') 
                {
                    pos.first = i;
                    pos.second = j;
                    break;
                }
            }
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        for (int i = pos.first + 1; i < N; ++i) 
        {
            if (board[i][pos.second] == 'B')
                break;
            if (board[i][pos.second] == 'p') 
            {
                ++res;
                break;
            }
        }
        for (int i = pos.first - 1; i >= 0; --i) 
        {
            if (board[i][pos.second] == 'B')
                break;
            if (board[i][pos.second] == 'p')
            {
                ++res;
                break;
            }
        }
        for (int j = pos.second + 1; j < N; ++j) 
        {
            if (board[pos.first][j] == 'B')
                break;
            if (board[pos.first][j] == 'p') 
            {
                ++res;
                break;
            }
        }
        for (int j = pos.second - 1; j >= 0; --j) 
        {
            if (board[pos.first][j] == 'B')
                break;
            if (board[pos.first][j] == 'p') 
            {
                ++res;
                break;
            }
        }
        return res;
    }
};
