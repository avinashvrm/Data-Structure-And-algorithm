class Solution {
public:
    void solve(vector<vector<char>>& grid,int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        //int dist = 1;
        grid[x][y] = '2';
        
        int dir_x[4] = {0,0,1,-1};
        int dir_y[4] = {1,-1,0,0};
        
        for(int i = 0; i<4 ;i++)
        {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            
            if(nx >=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1')
                solve(grid,nx,ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int k = 0;
        for(int i = 0;i<n; i++)
        {
            for(int j = 0;j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,i,j);
                    k++;
                }
                
            }
        }
        return k;
    }
};

