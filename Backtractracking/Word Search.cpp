class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int pos)
    {
        if(pos==word.size())
          return true;
        
        for(int k=0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y]==word[pos])
            {
                board[x][y] = '#';
                if(dfs(board,word,x,y,pos+1))
                    return true;
                else
                    board[x][y] = word[pos];
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    board[i][j] = '#';
                    if(dfs(board,word,i,j,1))
                        return true;
                    else
                        board[i][j]=word[0];
                }
                    
            }
        }
        return false;
    }
};
