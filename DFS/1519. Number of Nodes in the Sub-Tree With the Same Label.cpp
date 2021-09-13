//  https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// question pe jao padhao ur solve kro, one of the best implementation of dfs
class Solution {
public:
    vector<int> dfs(unordered_map<int,vector<int>> &mp,vector<bool> &vis,string &labels,int st,vector<int> &res)
    {
        vis[st] = true;
        vector<int> vec(26,0);
        vec[labels[st]-'a'] = 1;
        for(auto x : mp[st])
        {
            if(!vis[x])
            {
                vector<int> freq = dfs(mp,vis,labels,x,res);
                for (auto k = 0; k < 26; ++k)
                    vec[k] += freq[k];
            }
        }
        res[st] = vec[labels[st]-'a'];
        return vec;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        unordered_map<int,vector<int>> mp;
        for(auto e : edges)
        {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        vector<int> res(n,0);
        vector<bool> vis(n,false);
        
        dfs(mp,vis,labels,0,res);
        
        return res;
    }
};
