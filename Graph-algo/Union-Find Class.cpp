class DSU{
public:
    int parent[20001];
    int rank[20001];
    DSU()
    {
        for(int i=0; i<=20000; i++)
        {
            parent[i]=i;
            rank[i]=0;
         }
    }
    int find(int x)
    {
        if(parent[x]!=x)
          parent[x]=find(parent[x]);
        return parent[x];
    }
    bool _union(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        if(rank[xp]<rank[yp])
            parent[xp]=yp;
        else if(rank[yp]<rank[xp])
            parent[yp]=xp;
        else
        {
            parent[yp]=xp;
            rank[xp]++;
        }   
     }
     
};
