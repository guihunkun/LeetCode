class Solution {
public:
	inline bool checkWin(vector<string> & board, const char & c) {
		/* 判断行和列 */
		for (int i = 0; i < 3; ++i) {
			if (c == board[i][0] && c == board[i][1] && c == board[i][2]) {
				return true;
			}
			if (c == board[0][i] && c == board[1][i] && c == board[2][i]) {
				return true;
			}
		}
		/* 判断对角线 */
		if (c == board[0][0] && c == board[1][1] && c == board[2][2]) {
			return true;
		}
		if (c == board[2][0] && c == board[1][1] && c == board[0][2]) {
			return true;
		}
		return false;
	}
	bool validTicTacToe(vector<string> & board) {
		int count = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if ('X' == board[i][j]) {
					++count;
				}
				else if ('O' == board[i][j]) {
					--count;
				}
			}
		}
        if (count < 0 || count > 1){
            return false;
        }
		bool XWin = checkWin(board, 'X');
		bool OWin = checkWin(board, 'O');
		if (XWin && !OWin) {
			return 1 == count;
		}
		else if (!XWin && OWin) {
			return 0 == count;
		}
		else if (XWin && OWin) {
			return false;
		}
		return true;
	}
};

