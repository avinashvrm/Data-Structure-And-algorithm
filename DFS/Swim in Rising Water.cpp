class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n;
    vector<vector<bool>> vis;
    bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<n;
    }
    bool dfs(vector<vector<int>>& grid,int k,int x,int y)
    {
        vis[x][y] = true;
        if(x==n-1 && y==n-1)
            return true;
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(isValid(nx,ny) && !vis[nx][ny] && grid[nx][ny]<=k)
            {
                if(dfs(grid,k,nx,ny))
                    return true;
            }
        }
        return false;
    }
    bool possible(vector<vector<int>>& grid,int k,int x,int y)
    {
        vis.assign(n,vector<bool>(n,false));
        return dfs(grid,k,x,y);
    }
    int swimInWater(vector<vector<int>>& grid) 
    {
        n = grid.size();
        
        int l = grid[0][0];
        int h = 50*50;
        int ans =0;
        while(l<h)
        {
            int mid = (l+h)>>1;
            if(possible(grid,mid,0,0))
            {
                ans = mid;
                h = mid;
            }
            else
                l = mid+1;
        }
        return h;
    }
};
