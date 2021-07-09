class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int> res;
        vector<vector<int>> graph(n);
        
        vector<int> indegree(n,0);
        for(int i=0;i<pre.size();i++)
        {
            //cout<<"ha"<<i;
            graph[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        int k = n;
        for(int i=0;i<k;i++)
        {
            if(indegree[i]==0)
            {
                --n;
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();q.pop();
            
            for(auto x : graph[node])
            {   
                indegree[x]--;
                if(indegree[x]==0)
                {
                    res.push_back(x);       
                    n--;
                    q.push(x);
                }
            }
        }
        return n==0 ?res : vector<int>();
    }
};
