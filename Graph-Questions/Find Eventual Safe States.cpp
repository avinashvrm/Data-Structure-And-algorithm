// Question is asking us to find nodes that are not in a cycle
// Perform a simple DFS and keep track of visited nodes
// We know "leaf" nodes are safe, and any nodes with only safe "children" are also safe
// If we find a node already visited, we know it is not safe
// Keep track of these two things (safe and cycle nodes) and return the safe ones
class Solution {
public:
    vector<int> safe;
    vector<int> cycle;
    bool dfs(vector<vector<int>>& graph,int st, vector<bool> vis)
    {
        if (safe[st])  
            return true;  // we know safe already
	    if (cycle[st]) 
            return false; // we know in cycle already
        
        if(vis[st])
        {
            cycle[st] = true;
            return false;
        }
        vis[st] = true;
        
        for(int v : graph[st])
            if(!(dfs(graph,v,vis)))
            {
                cycle[st] = true;
                return false;
            }
        safe[st] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        safe.resize(n);
        cycle.resize(n);
        vector<int> res;
        vector<bool> vis(n,false);
        for(int i=0;i<graph.size();i++)
        {
            if(!cycle[i] && dfs(graph,i,vis))
                res.push_back(i);
        }
        return res;
    }
};
