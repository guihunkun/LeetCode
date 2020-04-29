class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        int row = click[0], col = click[1];
        if(board[row][col] == 'M' || board[row][col] == 'X'){
            board[row][col] = 'X';
            return board;
        }
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1,1}, {1, -1}, {-1,1}, {-1, -1}};
        int num = 0;
        for(auto dir: dirs){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && board[new_row][new_col] == 'M') num ++;
        }
        if(num > 0){
            board[row][col] = num + '0';
            return board;
        }
        board[row][col] = 'B';
        for(auto dir: dirs){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && board[new_row][new_col] == 'E'){
                vector<int> next_click = {new_row, new_col};
                updateBoard(board, next_click);
            }
        }
        return board;
    }
};
