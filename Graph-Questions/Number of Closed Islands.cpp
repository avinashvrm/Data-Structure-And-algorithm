class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y)
    {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        if(grid[x][y]==0)
        {
            grid[x][y]=2;

            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx < grid.size() && ny>=0 && ny < grid[0].size() && grid[nx][ny]==0)
                    dfs(grid,nx,ny);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<r;i++)
        {
            dfs(grid,i,0);
            dfs(grid,i,c-1);
        }
        for(int i=0;i<c;i++)
        {
            dfs(grid,0,i);
            dfs(grid,r-1,i);
        }
        int n=0;
        for(int i = 1;i<r-1;i++)
        {
            for(int j=1;j<c-1;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j);
                    n++;
                }
            }
        }
        return n;
    }
};
