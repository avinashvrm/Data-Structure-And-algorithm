class Solution {
public:
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    unordered_map<string,long long> dp;
    long long res = -1;
    void solve(vector<vector<int>>& grid,int x,int y,long long pro)
    {
        string key = to_string(x) + "##" + to_string(y) + to_string(pro);
        if(dp.find(key)!=dp.end())
            return ;
        dp[key] = pro;
        if(x==grid.size()-1 && y==grid[0].size()-1)
        {
            res = max(res,pro);
            return;
        }
        //long long k = 0;
        for(int i=0;i<2;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size())
                solve(grid,nx,ny,pro * grid[nx][ny]);
        }
    }
    int maxProductPath(vector<vector<int>>& grid) 
    {
        solve(grid,0,0,grid[0][0]);
        return res%1000000007;
    }
};
