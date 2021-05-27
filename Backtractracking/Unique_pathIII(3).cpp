class Solution {
public:
    int res = 0;
    void solve(vector<vector<int>>& grid,int x,int y,int c,int p)
    {
        if(grid[x][y]==2)
        {
            if(c==p)
                res++;
            
            return;
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && (grid[nx][ny]==0||grid[nx][ny]==2))
            {
                grid[x][y] = -1;
                solve(grid,nx,ny,c+1,p);
                grid[x][y] = 0;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int si =0,sj = 0,c=0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    si = i,sj=j;
                if(grid[i][j]!=-1)
                    c++;
            }
        }
        cout<<c;
        solve(grid,si,sj,1,c);
        return res;
    }
};
