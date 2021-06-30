class Solution
{
    public:
	bool dfs(int V, vector<int> adj[],int st,bool *vis,bool *ans)
	{
	    vis[st]=true;
	    ans[st]=true;
	    for(auto x : adj[st])
	    {
	        if(!vis[x])
	        {
	            if(dfs(V,adj,x,vis,ans))
	                return true;
	        }
	        else
	        {
	            if(ans[x])
	                return true;
	        }
	        
	    }
	    ans[st] = false;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    bool *vis = new bool[V+1]();//visited
	    bool *ans = new bool[V+1]();//ancestor
	    
	   	for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(V,adj,i,vis,ans))
                {
                    return true;
                }
            }
        }
        
        return false;
	}
};
