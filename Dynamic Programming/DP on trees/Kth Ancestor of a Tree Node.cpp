//BINARY LIFTING
//pepcoding ka video se explanaation!


class TreeAncestor {
public:
    const static int mx = 17;
    vector<vector<int>> table;
    TreeAncestor(int n, vector<int>& parent) 
    {
        table.resize(mx,vector<int> (n,-1));
        
        for(int i=0;i<n;i++)
            table[0][i] = parent[i];
        
        for(int i=1;i<mx;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(table[i-1][j]!=-1)
                    table[i][j] = table[i-1][table[i-1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
       for(int i=0;i<mx;i++)
       {
           int mask = (1<<i);
           if(k&mask)
           {
               node = table[i][node];
               if(node==-1)
                   return -1;
           }
       }
        return node;  
    }
};

