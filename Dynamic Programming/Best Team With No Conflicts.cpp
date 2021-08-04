//https://leetcode.com/problems/best-team-with-no-conflicts/
class Solution {
public:
    int solve(vector<vector<int>> &player,int pos,int mx,vector<vector<int>> &dp)
    {
        if(pos>=n)
            return 0;
        if(dp[pos][mx]!=-1)
            return dp[pos][mx];
        
        if(player[pos][1]>=mx)
        {
            return dp[pos][mx] = max(player[pos][0] + solve(player,pos+1,player[pos][1],dp),solve(player,pos+1,mx,dp));
        }
        else
            return dp[pos][mx] = solve(player,pos+1,mx,dp);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        n = scores.size();
        
        vector<vector<int>> player;
        for(int i=0;i<n;i++)
            player.push_back({scores[i],ages[i]});
        sort(player.begin(),player.end());
        
        vector<vector<int>> dp(1001,vector<int> (1001,-1));
        return solve(player,0,0,dp);
    }
private:
    int n;
};
