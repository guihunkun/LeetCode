class Solution 
{
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        if(board.size() == 0 || board[0].size() == 0)
            return 0;
        int count = 0;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.')
                    continue;
                else
                {
                    if((i-1 >= 0 && board[i-1][j] == 'X') || (j-1 >= 0 && board[i][j-1] == 'X') )
                        continue;
                    else
                        count++;
                }
            }
        }
        return count;
    }
};
