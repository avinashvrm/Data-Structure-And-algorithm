class Solution {
public:
    int dp[202][202];
    int solve(vector<vector<int>>& dungeon,int x,int y,int n,int m) 
    {
        if(x>=n || y>=m)
            return INT_MAX;
        if(dp[x][y])
            return dp[x][y];
        int health = min(solve(dungeon,x+1,y,n,m),solve(dungeon,x,y+1,n,m));
        
        if(health==INT_MAX)
            health = 1;
        
        int res = 0;
        if(health - dungeon[x][y]>0)
            res = health - dungeon[x][y];
        else
            res = 1;
        
        return dp[x][y] = res;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int n = dungeon.size();
        int m = dungeon[0].size();
        memset(dp,0,sizeof(dp));
        return solve(dungeon,0,0,n,m);
    }
};
