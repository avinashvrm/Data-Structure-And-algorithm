#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define lli long long int
#define vi vector<int>
#define pb push_back

bool Is_Subset(int arr[],int n,int s)
{
	bool t[n+1][s+1];

	for(int i=0;i<=s;i++)// intialisation..
		t[0][i] = false;

	for(int i=0;i<=n;i++)//intialisation..
		t[i][0] = true;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){

			if(arr[i] > s)
				t[i][j] = t[i-1][j];
			else if(arr[i] <= s)
				t[i][j] = t[i-1][j] || t[i-1][j-arr[i]];

		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			cout<<t[i][j]<<" ";
		}cout<<endl;
	}
	return t[n][s];
	
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;cin>>n;
	int arr[n];
	f(i,n) cin>>arr[i];
	int s;cin>>s;
	if(Is_Subset(arr,n,s)==true)
		cout<<"YES";
	else
		cout<<"NO";
}