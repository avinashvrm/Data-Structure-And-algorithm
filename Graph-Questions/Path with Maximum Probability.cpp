class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        unordered_map<int,vector<pair<int,double>>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({edges[i][1],succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0.0);
        
        pq.push({1.0,start});
        dist[start] = 1.0;
        while(!pq.empty())
        {
            auto [d,u] = pq.top();
            pq.pop();
            
            for(auto [v,prob] : mp[u])
            {
                if(dist[v]<dist[u]*prob)
                {
                    dist[v] = dist[u]*prob;
                    pq.push({dist[v],v});
                }
            }
        }
       
        return dist[end];
    }
};
