/*
Q) https://leetcode.com/problems/escape-a-large-maze/
   
   Explanation : https://www.youtube.com/watch?v=bZqIfxD902c&ab_channel=ShivamPatel

Idea : thinking in terms of blocking area...
       as blocks.size() is maximum 200 that means either src or target are trapped with some perimeter or they exist a path as its huge huge grid
       so what can be the maximum blockage (a blockage of line of blocks diagonally seperating src or target) 
       So what is the area where inside blocks are absent n*n-1/2 -- video dekh lo iske liye agr bhul gae ho tho!!
       Now just see if your free area is greater than max_area though blocks(using bfs)
       DONE
       */
using map2d = unordered_map<int,unordered_map<int,bool>>;
class Solution {
public:
    int n;
    int max_area;
    bool solve(map2d &mp,vector<int>& src, vector<int>& target)
    {
        int area = 1;
        queue<pair<int,int>> q;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        map2d vis;
        q.push({src[0],src[1]});
        
        vis[src[0]][src[1]] = true;
        int cap = 1e6;
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            if(p.first==target[0] && p.second==target[1])
                return true;
            
            if(area > max_area)
                return true;
            
            for(int i=0;i<4;i++)
            {
                int x = p.first + dx[i];
                int y = p.second+ dy[i];

                if(x>=0 && y>=0 && x<cap && y<cap && !mp[x][y] && !vis[x][y])
                {
                    q.push({x,y});
                    area++;
                    vis[x][y] = true;
                }
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
    {
        n = blocked.size();
        max_area = (n*(n-1))/2;
        map2d mp;
        for(int i=0;i<n;i++)
            mp[blocked[i][0]][blocked[i][1]]=true;
        
        return solve(mp,source,target) and solve(mp,target,source);
    }
};
