class Solution {
public:
    int dp[102][102];
    int solve(int m,int n,int x,int y)
    {
        if(x>= m || y>=n)
            return 0;
        
        if(x== m-1 && y==n-1)
            return 1;
        
        if(dp[x][y]!=-1)  
            return dp[x][y];
        
        int t = solve(m,n,x+1,y) + solve(m,n,x,y+1);
        
        return dp[x][y] = t;
    }
    int uniquePaths(int m,int n) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};
