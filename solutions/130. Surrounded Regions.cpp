class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(grid[i][j]=='O')
        {
            grid[i][j]='1';
            
            if(i+1 < grid.size()) 
                dfs(grid, i+1, j);
            
            if(i > 1) 
                dfs(grid, i-1, j);
            
            if(j+1 < grid[i].size()) 
                dfs(grid, i, j+1);
            
            if(j > 1) 
                dfs(grid, i, j-1);
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
