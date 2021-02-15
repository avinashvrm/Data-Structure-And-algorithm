class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size()-1;
        if(grid[0][0]==1 || grid[n][n]==1)
            return -1;
        int level = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                auto c = q.front();
                q.pop();
                int x = c.first;
                int y = c.second;
                
                if(x == n && y==n)
                    return 1+level;
                if(x<0 || y<0 || x>n || y>n || grid[x][y]>=1)
                    continue;
                
                grid[x][y] = 2;
                
                q.push({x,y+1});
                q.push({x,y-1});
                q.push({x+1,y});
                q.push({x-1,y});
                
                q.push({x+1,y+1});
                q.push({x-1,y-1});
                q.push({x+1,y-1});
                q.push({x-1,y+1});
            }
            level++;
        }
        return -1;
    }
};
