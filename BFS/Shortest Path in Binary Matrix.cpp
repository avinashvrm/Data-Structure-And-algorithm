/*class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int x,int y)
    {
        if(x < 0  || y < 0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==1)
            return false;
        
        return true;
    }
    void solve(vector<vector<int>>& grid,int x,int y,int dist,int &min_dist)
    {
        if(x==grid.size()-1 && y==grid[0].size()-1)
        {
            min_dist = min(dist,min_dist);
            return;
        }
        grid[x][y] = 1;
        
        int dx[8] = {0,0,1,-1,1,-1,1,-1};
        int dy[8] = {1,-1,0,0,1,-1,-1,1};
        
        for(int i =0;i<8;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isValid(grid,nx,ny))
            {
                solve(grid,nx,ny,dist+1,min_dist);
            }
        }
        grid[x][y] = 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1)
            return -1;
        int dist = 1;
        int min_dist = INT_MAX;
        solve(grid,0,0,dist,min_dist);
        return min_dist==INT_MAX? -1 : min_dist;
    }
    //This solution won't work beacuse n can be as large as 100 so it will give us TLE; BFS would work though 
};
*/
class Solution {
public:
    
    bool insideGrid(int X,int Y,int n, int m)
    {
        return X>=0 && Y>=0 && X<n && Y<m;
    }
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {

        // simple 8 direction BFS and keep track of visited 
        // T & S : O(N * M)
        vector<vector<int>> dir = { {-1,0}, {0,-1}, {0,-1},{-1,1}, {1,1}, {1,0}, {1,-1}, {0, 1}, {-1,-1}};
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int,int>> Q;


        //Push initial coordinate into the queue 
        if(grid[0][0]==0) 
        {
            Q.push({0,0});
            grid[0][0] = 1;
        }

        int steps=1;

        while(!Q.empty()) 
        {


            int qSize = Q.size(); 

            //While there is still paths to explore
            while(qSize--) 
            {
                auto [x, y] = Q.front(); 
                // cout << x << " " << y << "  " << endl;
                Q.pop();

                //If we've hit the end 
                if(x == n-1 && y == m-1) 
                    return steps;

                //Traverse all 8 possible directions
                for(auto& d: dir) 
                {
                    int X = x + d[0];
                    int Y = y + d[1];

                    if(insideGrid(X,Y,n,m) == true && grid[X][Y]==0)                      
                    {
                        grid[X][Y] = 1;
                        Q.push({X,Y});
                    }
                }

            }
            steps++;   
        }  
        return -1;
    }
};
