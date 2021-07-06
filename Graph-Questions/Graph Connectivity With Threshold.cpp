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
    void Union(int a1,int b1)
    {
        int a = find(a1);
        int b = find(b1);
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& q) 
    {
        ds.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            ds[i].parent = i;
            ds[i].rank = 1;
        }
        for(int i = threshold+1; i<=n; i++)
        {
            int m = 1;
            while(i*m<=n)
            {
                
                Union(i,i*m);
                m++;
            }
        }
        vector<bool> res;
        for(auto &x:q)
        {
            res.push_back(find(x[0])==find(x[1]));
        }
        return res;
    }
};
