#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define lli long long int
#define vi vector<int>
#define pb push_back

void print(vi &v)
{
	for(auto i : v)
		cout<<i<<" ";
	cout<<endl;
}
void blow_back(vi &v,int x,int n)
{
	if(x>n)
	{
		print(v);
		return;
	}
	for(int i = 0;i<2*n;i++)
	{
		if(v[i]==-1 && (i+x+1)<2*n && v[i+x+1]==-1)
		{
			v[i] = x;
			v[i+x+1] = x;
			
			blow_back(v,x+1,n);

			v[i] = -1;
			v[i+x+1] = -1;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	vi v(2*n,-1);
	int x = 1;
	blow_back(v,x,n);
	return 0;
}
