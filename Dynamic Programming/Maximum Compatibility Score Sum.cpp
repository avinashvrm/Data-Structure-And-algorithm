class Solution {
public:
    int ans = 0;
    void solve(vector<vector<int>>& students, vector<vector<int>>& mentors,vector<bool> &vis,int x,int &s,int m)
    {
        if(x>=m)
        {
            ans = max(ans,s);
            return;
        }
        for(int i = 0;i<m;i++)
        {
            if(vis[i]==false)
            {
                vis[i] = true;
                vector<int> t = mentors[i];
                vector<int> u = students[x];
                int cs = 0;
                for(int j=0;j<u.size();j++)
                {
                    if(t[j]==u[j])
                        cs++;
                }
                s = s+cs;
                solve(students,mentors,vis,x+1,s,m);
                s = s-cs;
                vis[i] = false;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
    {
        int m = students.size();
        vector<bool> vis(m,false);
        int s=0;
        solve(students,mentors,vis,0,s,m);
        return ans;
    }
};
