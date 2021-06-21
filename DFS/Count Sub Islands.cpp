class Solution {
public:
    void solve(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int x, int y,bool &flag)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        grid2[x][y] = 2;
        if(grid1[x][y] == 0)
            flag = false;
            
        int dir_x[4] = {0,0,1,-1};
        int dir_y[4] = {1,-1,0,0};
        
        for(int i = 0; i<4 ;i++)
        {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            
            if(nx >=0 && nx<n && ny>=0 && ny<m && grid2[nx][ny]==1)
                solve(grid1,grid2,nx,ny,flag);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int n = grid1.size();
        int m = grid1[0].size();
        int k = 0;
        for(int i = 0;i<n; i++)
        {
            for(int j = 0;j<m; j++)
            {
                if(grid2[i][j]==1)
                {
                    bool flag = true;
                    solve(grid1,grid2,i,j,flag);
                    if(flag)
                        k++;
                }
                
            }
        }
        return k;
    }
};

