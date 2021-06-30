class Solution {
public:
    struct node
    {
        int parent;
        int rank;
    };
    vector<node> ds;
    int find(int v)
    {
        if(ds[v].parent==v)
            return v;
        else
            return ds[v].parent = find(ds[v].parent);//path compression
            
    }
    void Union(int a,int b)
    {
        if(ds[a].rank > ds[b].rank)
        {
            ds[b].parent = a;
            
        }
        else if(ds[b].rank > ds[a].rank)
        {
            ds[a].parent = b;   
        }
        else
        {
            ds[a].parent = b;
            ds[b].rank+=1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int V = edges.size();
        ds.resize(V+1);
        queue<pair<int,int>> q;
        for(int i=1;i<=V;i++)
        {
            ds[i].parent = i;
            ds[i].rank = 0;
        }
        for(int i=0;i<edges.size();i++)
        {
            int fromP = find(edges[i][0]);
            int toP   = find(edges[i][1]);
            
            if(fromP==toP)
                q.push({edges[i][0],edges[i][1]});
            
            Union(fromP,toP);
        }
        return {q.front().first,q.front().second};
    }
};
