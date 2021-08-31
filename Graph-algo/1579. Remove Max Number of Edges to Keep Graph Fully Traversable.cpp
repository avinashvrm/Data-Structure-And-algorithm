class Solution {
public:
    struct dsu{
        vector<int> parent,count;
        dsu(int n)
        {
            parent = vector<int> (n);
            count = vector<int> (n,1);
            for(int i =0;i<n;i++)
                parent[i] = i;
            
        }
        int find(int v)
        {
            if(parent[v]==v)
                return v;
            return parent[v] = find(parent[v]);
        }
        bool join(int x,int y)
        {
            int a = find(x);
            int b = find(y);
            if(a==b)
                return false;
            if(count[a]<count[b])
                swap(a,b);
            parent[b] = a;
            count[a]+=count[b];
            return true;
        }
        int size(int x)
        {
            return count[find(x)];
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        vector<pair<int,int>> alice;
        vector<pair<int,int>> bob;
        vector<pair<int,int>> both;
        
        for(auto &x:edges)
        {
            if(x[0]==1)
                alice.push_back({x[1]-1,x[2]-1});
            else if(x[0]==2)
                bob.push_back({x[1]-1,x[2]-1});
            else
                both.push_back({x[1]-1,x[2]-1});
        }
        int res=0;
        dsu a(n),b(n);
        for(auto x:both)
        {
            res+=a.join(x.first,x.second);
            b.join(x.first,x.second);
        }
        for(auto x : alice)
            res+=a.join(x.first,x.second);
        for(auto x : bob)
            res+=b.join(x.first,x.second);
        // cout<<res<<endl;
        // cout<<a.size(a.find(0))<<" "<<b.size(b.find(1));
        if(a.size(a.find(1))<n || b.size(b.find(1)) < n)
            return -1;
        return (int)edges.size() - res;
        
    }
};
