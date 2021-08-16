//https://leetcode.com/problems/filling-bookcase-shelves/
class Solution {
public:
    int n;
    int solve(vector<vector<int>>& books, int i,int W,int sw,int max_ht,vector<vector<int>> &dp)
    {
        if(i>= n)
            return max_ht;
        if(dp[i][sw]!=-1)
            return dp[i][sw];
        int w = books[i][0];
        int h = books[i][1];
        int op1 = INT_MAX;
        int op2 = INT_MAX;
        
        if(sw+w <= W)
        {
            //int max_h = ;
            op1 = solve(books,i+1,W,sw+w,max(max_ht,h),dp);
        }
        op2 = max_ht + solve(books,i+1,W,w,h,dp);
        return dp[i][sw] = min(op1,op2);
    }
    int minHeightShelves(vector<vector<int>>& books, int W) 
    {
        n = books.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return solve(books,0,W,0,0,dp);
    }
};
