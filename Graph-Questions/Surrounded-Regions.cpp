// Main idea sare boundry vale 'O' pr dfs chalana h, 'X' ko kaese cover kare ye sochne se kam nai banega hero!
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y)
    {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        if(grid[x][y]=='O')
        {
            grid[x][y]='1';
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < grid.size() && nx >= 0 && ny < grid[0].size() && ny >= 0)
                    dfs(grid,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i = 0; i<r; i++)
        {
            dfs(grid,i,0);//dono col ke liye 
            dfs(grid,i,c-1);
        }
        for(int j = 1; j<c-1; j++)// dono row ke liye
        {
            dfs(grid,0,j);
            dfs(grid,r-1,j);
        }
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j] == '1')
                    grid[i][j] = 'O';
                else
                    grid[i][j] = 'X';
            }
        }
        return;
    }
};
