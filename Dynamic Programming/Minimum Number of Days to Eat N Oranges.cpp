/*
There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:
Eat one orange.
If the number of remaining oranges (n) is divisible by 2 then you can eat  n/2 oranges.
If the number of remaining oranges (n) is divisible by 3 then you can eat  2*(n/3) oranges.
You can only choose one of the actions per day.
Return the minimum number of days to eat n oranges.

Example 1:

Input: n = 10
Output: 4
Explanation: You have 10 oranges.
Day 1: Eat 1 orange,  10 - 1 = 9.  
Day 2: Eat 6 oranges, 9 - 2*(9/3) = 9 - 6 = 3. (Since 9 is divisible by 3)
Day 3: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. 
Day 4: Eat the last orange  1 - 1  = 0.
You need at least 4 days to eat the 10 oranges.

   We have to avoid n-1 wala operation any how!, + we can't use dp vector bcz of constraint
   So n-1 can be avoided by directly pushing n to n%3 or n%2
*/
class Solution {
public:
    using ll =long long;
    ll solve(ll n,unordered_map<ll,ll> &dp)
    {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        
        if(dp.count(n))
            return dp[n];
        
        ll b=INT_MAX/2,c=INT_MAX/2;
        //ll k = min(n%3,n%2);
        b = 1 + n%3 + solve(n/3,dp);
        
        c = 1 + n%2 + solve(n/2,dp);
        
        return dp[n] = min(b,c);
    }
    int minDays(int n) 
    {
        res = 0;
        unordered_map<ll,ll> dp;
        return solve(n,dp);
        
    }
};
