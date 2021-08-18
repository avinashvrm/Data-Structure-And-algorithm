// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200

// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
class Solution {
public:
    int dp[101][101];
    int dfs(unordered_map<int, vector<pair<int, int>>> &hm,int src,int d,int k)
    {
        if(src==d)
            return 0;
        if(k==-1)
            return INT_MAX;
        if(dp[src][k]!=-1)
            return dp[src][k];
        
        int ans = INT_MAX;
        //vis[src] = true;
        for(auto x : hm[src])
        {
            int distance = dfs(hm,x.first,d,k-1);

            if(distance!=INT_MAX)
                ans = min(ans,distance + x.second);
        }
        return dp[src][k] = ans;
            
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int k) 
    {
        //vector<int> dis(n,INT_MAX);
        //vector<int> vis(n,false);
        
        unordered_map<int, vector<pair<int, int>>> hm;
        for (int i = 0; i < flights.size(); i++)
            hm[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        
        memset(dp,-1,sizeof(dp));
        int res = dfs(hm,s,d,k);
        
        return res==INT_MAX? -1 : res;
    }
};

