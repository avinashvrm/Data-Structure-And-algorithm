class Solution {
public:
                                                                             // Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
                                                                             // Output: 7
                                                                             // Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
    int solve(vector<vector<int>>& events,int n,int pos,int k,vector<vector<int>>& dp)
    {
        if(pos>=n || k==0)
            return 0;
        if(dp[pos][k]!=-1)
            return dp[pos][k];
        int i = pos+1;
        while(i<n && events[i][0]<=events[pos][1])
            i++;
        
        int inl = events[pos][2] + solve(events,n,i,k-1,dp);
        int exl = solve(events,n,pos+1,k,dp);
        
        return dp[pos][k] = max(inl,exl);
    }
    int maxValue(vector<vector<int>>& events, int k)
    {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events,n,0,k,dp);
    }
};
