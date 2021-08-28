class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n,m;
    bool dfs(vector<vector<char>>& grid,vector<vector<bool>> &vis,int x,int y,pair<int,int> p)
    {
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx<n && ny>=0 && ny<m)
            {
                if(vis[nx][ny] && nx!=p.first && ny!=p.second && grid[nx][ny]==grid[x][y])
                {
                    cout<<x<<" "<<y<<endl;
                    cout<<nx<<" "<<ny<<endl;
                    return true;
                }
                 
                if(vis[nx][ny] || grid[nx][ny]!=grid[x][y])
                    continue;
                
                vis[nx][ny] = true;
                if(dfs(grid,vis,nx,ny,{x,y}))
                    return true;       
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    vis[i][j] = true;
                    pair<int,int> p = {-1,-1};
                    if(dfs(grid,vis,i,j,p))
                        return true;
                }
            }
        }
        return false;
    }
};
