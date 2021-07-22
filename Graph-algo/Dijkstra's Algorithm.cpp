vector < pair < int , int > > v [SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
bool vis [SIZE];

void dijkstra()
{
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;
    multiset<pair<int,int>>s ;          // multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty())
    {
        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++)
        {
            int e = v[x][i].first; int w = v[x][i].second;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}
// using min heap
void dijkstra()
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
			
		}
	};
