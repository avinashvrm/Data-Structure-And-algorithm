class Solution {
public:
    int dp[1002][2][102];
    int solve(vector<int>& prices,int i,bool buy,int k)
    {
        if(i>=prices.size() || k==0)
            return 0;
        
        int temp;
        buy?temp=1:temp=0 ;
        
        if(dp[i][temp][k]!=-1)
            return dp[i][temp][k];
        
        if(buy)
        {
            int bought = -prices[i] + solve(prices,i+1,!buy,k);
            int skip = solve(prices,i+1,buy,k);
            
            return dp[i][temp][k] = max(bought,skip);
        }
    
        int sold = prices[i] + solve(prices,i+1,!buy,k-1);
        int skip = solve(prices,i+1,buy,k);
        return dp[i][temp][k] = max(sold,skip);
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        memset(dp , -1 , sizeof(dp)) ;
        return solve(prices,0,true,k);
    }
};
