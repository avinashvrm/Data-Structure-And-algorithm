
//Avdhesh
int dp[11][(1<<11)];
int solve(int prev,int n,int mask,vector<vector<int>>& cost){
    if(mask==0)
    {
        return cost[prev][0];
    }
    if(dp[prev][mask]!=-1)
    {
        return dp[prev][mask];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if((1<<i)&mask)
            ans=min(ans,cost[prev][i]+solve(i,n,mask^(1<<i),cost));
    }
    return dp[prev][mask]=ans;
}
int total_cost(vector<vector<int>>cost)
{
    memset(dp,-1,sizeof(dp));
    int n=cost.size();
    int mask=(1<<n)-1;
    mask=mask^(1);
    return solve(0,n,mask,cost);
}
