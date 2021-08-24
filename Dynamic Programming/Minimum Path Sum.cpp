/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

Becoz of constraint regular dfs will not work!!!!!!!!!!
*/
class Solution {
public:
    int dp[202][202];
    int solve(vector<vector<int>>& grid,int i, int j)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        if(i>=grid.size() || j>=grid[0].size())
            return INT_MAX;
      
        if(dp[i][j])
            return dp[i][j];
        int d,r;
      
        if(i<grid.size())
            d = solve(grid,i+1,j);
        if(j<grid[0].size())
            r = solve(grid,i,j+1);
        
        return dp[i][j] = grid[i][j] + min(d,r);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        memset(dp,0,sizeof(dp));
        return solve(grid,0,0);
    }
};


//Bottom Up DP - Table Filling

int getMinPath(vector <vector <int>> &grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector <vector <int>> dp(r, vector <int>(c, 0));
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < c; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        
        for (int i = 1; i < r; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
         
        return dp[r - 1][c - 1];
    }
