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
void updateTree(vector<int>& tree,int n,int i,int val)
{
    i++;
    while(i<=n)
    {
        tree[i]+=val;
        i+=i&(-i);
    }
}
int getSum(vector<int> tree,int n,int i)
{
    i++;
    int sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=i&(-i);
    }
    return sum;
}
void createTree(vector<int> v,int n,vector<int>& tree)
{
    vector<int> pre(n+1);
    pre[1] = v[0];

    for(int i=2;i<=n;i++)
        pre[i] = pre[i-1] + v[i-1];

    for(int i=1;i<=n;i++)
    {
        int idash = i-(i&-i);
        tree[i] = pre[i] - pre[idash];
    }
    // for(int i=0;i<n;i++)
    // {
    //     updateTree(tree,n,i,v[i]);//this is nlog(n)
    // }
}
int main(){
    s_g_c();
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> tree(n+1,0);
    createTree(v,n,tree);
    for(int i=1;i<=n;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    cout<<getSum(tree,n,3)<<endl;
    
    //update
    v[3]=6;
    updateTree(tree,n,3);//diff b/w new and old value
    cout<<getSum(tree,n,4);

}
