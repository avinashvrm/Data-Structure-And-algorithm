#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int sgt[200005];
void build(int n)
{
    //size is 2*n so we have filled from n to 2n-1
    for(int i=n-1;i>=1;i--){
            //if i is parent then it's left child is 2*i and it's right child is 2*i+1
        sgt[i]=sgt[2*i]+sgt[2*i+1];
    }
}
int query(int l, int r, int n)
{
    l+=n;
    r+=n;
    int sum=0;
    while(l<=r)
    {
        if(l&1)
        {
            sum=sum+sgt[l];
            l++;
        }
        if(!(r&1))
        {
            sum=sum+sgt[r];
            r--;
        }
        l=l>>1;//l=l/2;
        r=r>>1;//r=r/2;
    }
    return sum;
}
 
void update(int in, int n,int value)
{
    in+=n;
    sgt[in]=value;
    //for root in=1
    while(in>1)
    {
      in=in>>1;//in=in/2;
      //in=1
      sgt[in] = sgt[in*2]+sgt[in*2+1];
    }
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sgt[n+i]=arr[i];
    }
 
    build(n);
 
    while(q--)
    {
        int type;
        cin>>type;
 
        if(type==0){
           int l,r;
           cin>>l>>r;
           cout<<query(l,r,n)<<"\n";
        }
        else
        {
          int in,val;
          cin>>in>>val;
          update(in,n,val);
        }
 
    }
    return 0;
}
