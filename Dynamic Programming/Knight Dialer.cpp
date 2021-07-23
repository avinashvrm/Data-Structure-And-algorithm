//optimal substructure
class Solution {
public:
    int mod=1000000007;
    vector<vector<int>>v={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    
    int knightDialer(int n) {
        vector<vector<int>>dp(n+1,vector<int>(10,0));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i==1)
                {
                    dp[i][j]=1;
                    continue;
                }
                for(auto nextSquare:v[j])
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][nextSquare])%mod;
                }
            }
        }
        for(int j=0;j<10;j++)
        {
            ans=(ans+dp[n][j])%mod;
        }
        return ans;
    }
};
