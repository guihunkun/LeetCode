class Solution 
{
private:
    int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;
    bool inArea(int x,int y)
    {
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }
    bool searchword(const vector<vector<char>>& board,string& word,int index,int startdx,int startdy)
    {
        if(index==word.size()-1)
            return word[index]==board[startdx][startdy];
        if(board[startdx][startdy]==word[index])
        {
            for(int i=0;i<4;i++)
            {
                visited[startdx][startdy]=true;
                int newdx=startdx+d[i][0];
                int newdy=startdy+d[i][1];
                if(inArea(newdx,newdy) && !visited[newdx][newdy] && searchword(board,word,index+1,newdx,newdy))
                    return true;
            }
            visited[startdx][startdy]=false;
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        m=board.size();
        assert(m>0);
        n=board[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(searchword(board,word,0,i,j))
                    return true;
        return false;        
    }
};
