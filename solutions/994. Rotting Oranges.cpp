class Solution {
public:
    void add_neighbour(pair<int,int> cd,queue<pair<int,int>> &rotten,vector<vector<int>>& grid,int r,int c,int &fresh)
    {
        int x = cd.first;
        int y = cd.second;
        
        if(x>0 && grid[x-1][y]==1)
        {
            grid[x-1][y] = 2;
            fresh--;
            rotten.push({x-1,y});
        }
        if(y>0 && grid[x][y-1]==1)
        {
            grid[x][y-1] = 2;
            fresh--;
            rotten.push({x,y-1});
        }
        if(x < r-1 && grid[x+1][y]==1)
        {
            grid[x+1][y] = 2;
            fresh--;
            rotten.push({x+1,y});
        }
        if(y < c-1 && grid[x][y+1]==1)
        {
            grid[x][y+1] = 2;
            fresh--;
            rotten.push({x,y+1});
        }
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int r = grid.size();
