class Solution {
public:
    int maxDistance(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        queue<pair<int,int> > q;
        vector<vector<int> > dist(n, vector<int> (m, INT_MAX));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        int max_dist = -1;
        while(!q.empty())
        {
            int sz = q.size();

            
            for(int i=0; i<sz; i++)
            {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(int j=0; j<4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        if(dist[nx][ny] > dist[x][y] + 1)
                        {
                            dist[nx][ny] = 1 + dist[x][y];
                            q.push({nx,ny});
                            max_dist = max(max_dist,dist[nx][ny]);
                        }
                    }
                }
            }
        }

        return max_dist;
    }
};
