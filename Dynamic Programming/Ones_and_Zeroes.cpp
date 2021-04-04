class Solution {
    
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<string>& str, int zero, int one,int index)
    {
        if(index == str.size() || zero <0 || one <0)
            return 0;
        
        if(dp[zero][one][index]!=-1)
           return dp[zero][one][index];
        
        vector<int> count;
        count = help(str[index]);
        int ret=0;
        
        ret = solve(str,zero,one,index+1);
        if(zero >= count[0] && one >= count[1])
        {
            ret = max(ret,1 + solve(str,zero - count[0],one - count[1],index+1));
        }
        
        dp[zero][one][index] = ret;
        return dp[zero][one][index];
    }
    vector<int> help(string s)
    {
        vector<int> v(2);
        for(auto x : s)
            v[x - '0']++;
        return v;
    }
    int findMaxForm(vector<string>& str, int m, int n) 
    {
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(str.size()+1, -1)));
        return solve(str,m,n,0);
    }
};
