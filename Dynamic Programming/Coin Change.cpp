/*
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
*/

class Solution {
public:
    int dp[20][10001];
    int solve(vector<int>& coins, int n,int amount)
    {
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        if(amount==0)
            return 0;
        if(n==0)
            return INT_MAX - 1;
        
        if(coins[n-1] <= amount)
            return dp[n][amount] = min(1 + solve(coins,n,amount - coins[n-1]),solve(coins,n-1,amount));
        else
            return dp[n][amount] = solve(coins,n-1,amount);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int k = solve(coins,n,amount);
        if(k == INT_MAX - 1 )
            return -1;
        else
            return k;
    }
};
