//see the hint section in leetcode
class Solution {
public:
    int dx[4] = {0,0,1,-1}; 
    int dy[4] = {1,-1,0,0};
    bool visited[100][100] ={false};
    int distance[100][100];
    
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++) 
            { 
                if(grid[i][j])
                {
                    q.push({i,j});
                    visited[i][j]=true;
                    distance[i][j]=0;
                }
            }
        }
        // do a BFS traversal from all land('1') cells
        while(!q.empty()) 
        {
            pair<int,int> v = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x = v.first + dx[i];
                int y = v.second + dy[i];
                if(x>=0 && y>=0 && x<n && y<n && !visited[x][y])
                {
                    q.push({x,y});
                    visited[x][y] = true;
                    distance[x][y] = 1+distance[v.first][v.second];
                    ans = max(ans,distance[x][y]);
                }
            }
        }
        return ans==0 ? -1 : ans;
    }
};
