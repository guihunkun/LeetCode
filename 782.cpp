class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        bool is_one=true;
        int count=0;
        for(int i=0;i<board[0].size();++i){
            if(is_one ^ board[0][i])++count;
            is_one=!is_one;
        }
        if(count*2<=board[0].size() && !(count%2))is_one=true;
        else if((board[0].size()%2) && !(count%2))is_one=true;
        else is_one=false;

        int counter_col=0;
        for(int i=0;i<board[0].size();++i){
            if(is_one ^ board[0][i]){
                int j=i+1;
                bool is_one_buf=!is_one;
                while(j<board[0].size() && 
                (!(is_one_buf^board[0][j])||(board[0][i]==board[0][j]))){
                    ++j;
                    is_one_buf=!is_one_buf;
                }

                if(j==board[0].size())return -1;
                swap_col(board,i,j);
                ++counter_col;
            }
            is_one=!is_one;
        }

        is_one=true;
        count=0;
        for(int i=0;i<board.size();++i){
            if(is_one ^ board[i][0])++count;
            is_one=!is_one;
        }
        if(count*2<=board.size() && !(count%2))is_one=true;
        else if((board.size()%2) && !(count%2))is_one=true;
        else is_one=false;

        int counter_row=0;
        for(int i=0;i<board.size();++i){
            if(is_one ^ board[i][0])++counter_row;
            for(int j=1;j<board[0].size();++j){
                if(board[i][j]==board[i][j-1])return -1;
            }
            is_one=!is_one;
        }

        if(counter_row%2)return -1;
        return counter_col+counter_row/2;
    }

    void swap_col(vector<vector<int>>& board,int i,int j){
        for(int k=0;k<board.size();++k){
            int buf=board[k][i];
            board[k][i]=board[k][j];
            board[k][j]=buf;
        }
    }
};
