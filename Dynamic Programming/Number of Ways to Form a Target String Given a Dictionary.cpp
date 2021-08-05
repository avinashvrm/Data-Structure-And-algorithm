//https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// avdhesh ka bht hi pyra solution

class Solution {
public:
    #define ll long long int
    #define N 1005
    ll mod=1000000007;
    ll dp[1005][1005];
    vector<string> words;
    string target;
    vector<vector<ll>> mp;
    
    ll solve(int p1,int p2)
    {
        if(p2==target.size())
            return 1;
        
        if(p1==words[0].size())
            return 0;
        
        if(dp[p1][p2]!=-1)
            return dp[p1][p2];
        
        ll ans=0;
        
        ans+=(mp[p1][target[p2]-'a']*solve(p1+1,p2+1));
        ans%=mod;
        ans+=solve(p1+1,p2);
        ans%=mod;
        return dp[p1][p2]=ans;
    }
    int numWays(vector<string>& w, string t)
    {
        memset(dp,-1,sizeof(dp));// dp vector
        words=w;
        target=t;
        vector<vector<ll>> mp1(1005,vector<ll>(1005,0));// iske vajah se TLE bach rha h, ek word ke index pe no. of letter O(1) m mil jaega
        for(int i=0;i<w.size();i++)
        {
            for(int j=0;j<w[i].size();j++){
                mp1[j][w[i][j]-'a']++;
            }
        }
        mp=mp1;
        return solve(0,0);
    }
};
