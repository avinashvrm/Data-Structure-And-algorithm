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
        int c = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int,int>> rotten;
        for(int i=0; i<r; i++)
        {
           for(int j=0; j<c; j++)
           {
                if(grid[i][j]==2)
                    rotten.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
           }
        }
        while(!rotten.empty())
        {
            int cnt = rotten.size();
            for(int i =0;i<cnt; i++)
            {
                auto cd = rotten.front();//  cd----Co-Ordinates
                rotten.pop();
                
                add_neighbour(cd,rotten,grid,r,c,fresh);
            }
            if(rotten.size())// If there's no oranges to be rot then the queue would be empty.
                time++;         
        }
        return fresh==0? time:-1;
    }
};
