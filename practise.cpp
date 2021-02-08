#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define intt long long int
#define vi vector<int>
#define fr first
#define sc second                                                  
#define pb push_back

int main() 
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> v;
	    v.pb(1);
	    for(int x=2; x<=n; x++)
	    {
	        int carry = 0;
	        for(int i=0;i<v.size();i++)
	        {
	            int mul = v[i]*x + carry;
	            v[i] = mul%10;
	            carry = mul/10;
	        }
	        while(carry)
	        {
	            v.pb(carry%10);
	            carry = carry/10;
	        }
	    }
	    for(int i=v.size()-1;i>=0;i--){
	        cout<<v[i];
	    }
	    cout<<endl;
	    
	}
	return 0;
}