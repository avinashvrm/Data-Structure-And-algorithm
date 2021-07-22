// using Dijkstras Algorithm
class Solution {
	public:
		int networkDelayTime(vector<vector<int>>& times, int N, int K) 
        {
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
			vector<int>dist(N+1, INT_MAX);
			
			pq.push({0, K});
			dist[K] = 0;
			
			unordered_map<int, vector<pair<int, int>>>hm;
			for (int i = 0; i < times.size(); i++)
				hm[times[i][0]].push_back({times[i][1], times[i][2]});
			
			while (!pq.empty()) 
            {
				pair<int, int>p = pq.top();
				pq.pop();
				
				int u = p.second;
				for (auto it : hm[u]) 
                {
					int v = it.first;
					int w = it.second;
					
					if (dist[v] > dist[u] + w)
                    {
						dist[v] = dist[u] + w;
						pq.push({dist[v], v});
					}
				}
			}
			
			int res = 0;
			for (int i = 1; i <= N; i++)
				res = max(res, dist[i]);
			
			return res == INT_MAX ? -1 : res;
		}
	};
