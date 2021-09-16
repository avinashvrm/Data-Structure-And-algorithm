/* https://leetcode.com/problems/stone-game-iii/

            That's how optimal game strategy works. Expect your opponent to be playing optimally
            -When it's your turn, do your best
            -When it's your opponent's turn, expect the worst (that's why min() is taken below)
 */
 
 
 
 
 class Solution {
public:
     int dp[50005];
    int solve(vector<int> &stone,int indx)
    {
        if(indx>=stone.size())
            return 0;
        if(dp[indx]!=-1) 
            return dp[indx];
        
        int alice = 0;
        int res = INT_MIN;
        for(int i=indx;i<min((int)stone.size(),indx+3);i++)
        {
            alice +=stone[i];
            res = max(res,alice + min({solve(stone,i+2),solve(stone,i+3),solve(stone,i+4)}));
        }
        
        return dp[indx] = res;
    }
    string stoneGameIII(vector<int>& stone)
    {
        int totalscore = accumulate(stone.begin(),stone.end(),0);
        memset(dp,-1,sizeof dp);
        int alice = solve(stone,0);
        int bob = totalscore - alice;
        if(alice>bob)
            return "Alice";
        else if(alice<bob)
            return "Bob";
        else
            return "Tie";
    }
};
