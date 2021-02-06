#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define lli long long int
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
int MAH(int a[],int n)
{
	vi left;
	stack<pair<int,int>> s1;
	int pleft = -1; 
	for(int i=0;i<n;i++)
	{
		if(s1.empty()==true){
			left.pb(pleft);
		}
		else if(s1.empty()==false&&s1.top().first<a[i])
		{
			left.pb(s1.top().second);
		}
		else if(s1.empty()==false&&s1.top().first>=a[i])
		{
			while(s1.empty()==false&&s1.top().first>=a[i])
			{
				s1.pop();
			}
			if(s1.empty()==true)
				left.pb(pleft);
			else
				left.pb(s1.top().second);

		}
		s1.push({a[i],i});
	}
	vi right,width,area;
	stack<pair<int,int>> s2;
	int pright = n; 
	for(int i=n-1;i>=0;i--)
	{
		if(s2.empty()==true){
			right.pb(pright);
		}
		else if(s2.empty()==false&&s2.top().first<a[i])
		{
			right.pb(s2.top().second);
		}
		else if(s2.empty()==false&&s2.top().first>=a[i])
		{
			while(s2.empty()==false&&s2.top().first>=a[i])
			{
				s2.pop();
			}
			if(s2.empty()==true)
				right.pb(pright);
			else
				right.pb(s2.top().second);

		}
		s2.push({a[i],i});
	}
	reverse(right.begin(),right.end());
	for(int i=0;i<n;i++){
		width.pb((right[i]-left[i])-1);
		area.pb(width[i]*a[i]);
	}
	return *max_element(area.begin(),area.end());
}
int main()
{
	s_g_c();
	int n,m;
	cin>>n>>m;
	int a[n][m];
	f(i,n)
		for(int j=0;j<m;j++)
				cin>>a[i][j];
	int ar[m];
	for(int i=0;i<m;i++)
	{
		ar[i]=a[0][i];
	}
	int maxarea = MAH(ar,m);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==0)
				ar[j]=0;
			else
				ar[j]=ar[j]+a[i][j];
		}
		maxarea=max(maxarea,MAH(ar,m));
	}
	cout<<maxarea;
}