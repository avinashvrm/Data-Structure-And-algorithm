/*
class Solution {
public:
    vector<int> graph[100001];
    bool dfs(int st,vector<bool> &vis,vector<bool> &ans)
    {
        vis[st] = true;
        ans[st] = true;
        for(auto c : graph[st])
        {
            if(!vis[c] && dfs(c,vis,ans))
                return true;
            else if(ans[c])
                return true;
        }
        ans[st] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        int E = pre.size();
        vector<bool> vis(n,false);
        vector<bool> ans(n,false);
        for(int i=0;i<E;i++)
        {
            int x = pre[i][0];
            int y = pre[i][1];
            graph[x].push_back(y);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
            {
                if(dfs(i,vis,ans))
                    return false;
            }
        return true;
    }
};*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        
        for(int i = 0; i<prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        
        for(int i = 0; i<degree.size(); i++)
        {
            if(degree[i] == 0)
            {
                zeroDegree.push(i);
                numCourses--;
            }
        }
        
        while(!zeroDegree.empty())
        {
            int node = zeroDegree.front();
            zeroDegree.pop();
            for(int i = 0; i<graph[node].size(); i++)
            {
                int connectedNode = graph[node][i];
                degree[connectedNode]--;
                
                if(degree[connectedNode] == 0)
                {
                    zeroDegree.push(connectedNode);
                    numCourses--;
                }
            }
        }
        
        return numCourses == 0;
    }
};
