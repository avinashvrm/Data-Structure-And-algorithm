class Solution {
public:
    using ll = long long;
    using pi = pair<ll,ll>;
    inline int dist(vector<int>& a, vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        unordered_map<ll,vector<pi>> gp;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                vector<int> from = points[i];
                vector<int> to = points[j];
                
                ll dist = abs(from[0] - to[0]) + abs(from[1] - to[1]);
                gp[i].push_back({j,dist});
                gp[j].push_back({i,dist});
            }
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        ll cost = 0;
        pq.push({0,0});
        vector<bool> vis(n,false);
        vector<int> minDist(points.size(), 100000000);//for optimization purpose(nai bhi hoga tho chalega)
    
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            if(vis[p.second])
                continue;
            vis[p.second] = true;
            cost+=p.first;
            for(auto x : gp[p.second])
            {
                ll d = dist(points[p.second], points[x.first]);
                if(!vis[x.first] && d < minDist[x.first])
                {
                    pq.push({d,x.first});
                    minDist[x.first] = d;
                }
            }
        }
        return cost;
    }
};
