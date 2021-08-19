//https://codeforces.com/problemset/problem/1020/B

#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define ll long long
#define vi vector<int> 
#define pb push_back
 
void s_g_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void dfs(vector<int> &st,int n,vector<bool> vis,int p,int &ans)
{
    if(vis[p])
    {
        ans= p;
        return;
    }
    vis[p]=true;
    dfs(st,n,vis,st[p],ans);
}
 
int main()
{
    s_g_c();
    int n;
    cin>>n;
    vector<int> st(n+1);
    for(int i=1;i<=n;i++)
        cin>>st[i];
    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        vector<bool> vis(n+1,false);
        int ans = 0;
        dfs(st,n,vis,i,ans);
        res.push_back(ans);
    }
    for(auto x : res)
        cout<<x<<" ";
    return 0;
}
