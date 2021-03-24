#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define lli long long int
#define vi vector<int>
#define pb push_back


bool is_safe(vector<int> graph[],int c,int color[],int v)
{
	for(auto x : graph[v])
		if(color[x]==c)
			return false;
	return true;
}
bool blow_back(vector<int> graph[],int v,int color[],int V,int m)
{
	if(v==V)
		return true;
	for(int c = 1;c<=m;c++)
	{
		if(is_safe(graph,c,color,v))
		{
			color[v] = c;
			if(blow_back(graph,v+1,color,V,m)==true)
				return true;
			color[v] = 0;
		}
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// vector of graph edges as per the above diagram
    vector<vector<int>> edges
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };
 
    // total number of nodes in the graph
    int V = 6;
	vector<int> graph[V];
	for(int i = 0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int v = 0;
	int color[V];
	for(int i = 0;i<V;i++)
		color[i]=0;
	int m;
	cin>>m;
	if(blow_back(graph,v,color,V,m)==false)
		cout<<"false";
	cout<<"true";
	return 0;
}
