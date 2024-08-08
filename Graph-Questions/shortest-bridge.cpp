/*
https://leetcode.com/problems/shortest-bridge/description/
Intuition
This question is very similar to infection or disease spreading problem in tree / graph right(there we had to tell the time taken for it to spread to all), so thought process is similar for BFS
that we would have to know which all elements are belonging to first island then we would step forward in all directions to see if we have second island till we have found it.

Approach
It is pretty simple we just have to maintain a queue and visited
-> first we have to find all elements of first island and push it in the queue
->then do the BFS for all the elements simlutaneously by keeping track of current size of queue and after catering to all current elements then we will increase the ans by 1

->then repeat it for all the children pushed into the queue while doing previous loop until we find the first element of second island.

->just then we would return the ans.
*/

class Solution {
public:

    bool isValid(int i ,int j,vector<vector<int>>&grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()) return true;
        return false;
    }

    void dfs(int i ,int j,vector<vector<int>> &grid,queue<pair<int,int>>&q,vector<vector<int>>&visited){
        q.push(make_pair(i,j));
        grid[i][j]=2;
        visited[i][j]=1;
        //up
        if(isValid(i-1,j,grid) && grid[i-1][j]==1 && !visited[i-1][j]){
            dfs(i-1,j,grid,q,visited);
        }
        // down
        if (isValid(i+1, j,grid) && grid[i+1][j] == 1 && !visited[i+1][j]) {
            dfs(i+1, j, grid, q, visited); 
        }

        //left
        if (isValid(i, j-1,grid) && grid[i][j-1] == 1 && !visited[i][j-1]) {
            dfs(i, j-1, grid, q, visited); 
        }

        //right
        if (isValid(i, j+1,grid) && grid[i][j+1] == 1 && !visited[i][j+1]) {
            dfs(i, j+1, grid, q, visited); 
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int flag=0;
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    flag=1;
                    dfs(i,j,grid,q,visited);
                    break;
                }
            }
            if(flag) break;
        }

        //till here the first island elements has been marked as 2 and pushed into the queue
        
        int ans=0;
        while(!q.empty()){
            int currSize=q.size();
            for(int i =0;i<currSize;i++){
                auto ele=q.front();q.pop();
                int r=ele.first; int c=ele.second;
                visited[r][c]=1;
                //up
                if (isValid(r-1, c, grid) && !visited[r-1][c]) {
                    if (grid[r-1][c] == 1) return ans;
                    else if (grid[r-1][c] == 0) {
                        visited[r-1][c]=1;
                        q.push(make_pair(r-1, c));
                    }
                }
                //down
                if (isValid(r+1, c, grid) && !visited[r+1][c]) {
                    if (grid[r+1][c] == 1) return ans;
                    else if (grid[r+1][c] == 0) {
                        q.push(make_pair(r+1, c));
                        visited[r+1][c]=1;
                    }
                }
                //left
                if (isValid(r, c-1, grid) && !visited[r][c-1]) {
                    if (grid[r][c-1] == 1) return ans;
                    else if (grid[r][c-1] == 0) {
                        q.push(make_pair(r, c-1));
                        visited[r][c-1]=1;
                    }
                }
                //right
                if (isValid(r, c+1, grid) && !visited[r][c+1]) {
                    if (grid[r][c+1] == 1) return ans;
                    else if (grid[r][c+1] == 0) {
                        q.push(make_pair(r, c+1));
                        visited[r][c+1]=1;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
