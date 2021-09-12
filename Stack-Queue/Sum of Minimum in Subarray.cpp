#define ll long long
#define vi vector<int>
#define pb push_back
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) 
    {
        int n = a.size();  
        vi left;
        stack<pair<int,int>> s1;
        int pleft = -1; 
        for(int i=0;i<n;i++)
        {
            if(s1.empty())
            {
                left.push_back(pleft);
                s1.push({a[i],i});
                continue;
            }
            while(!s1.empty() && s1.top().first>=a[i])
                s1.pop();

            if(s1.empty()==true)
                left.pb(pleft);
            else
                left.pb(s1.top().second);
            
            s1.push({a[i],i});
        }
        // for(int i=0;i<n;i++)
        //     cout<<left[i]<<" ";
        // cout<<endl;
        vi right;
        stack<pair<int,int>> s2;
        int pright = n; 
        for(int i=n-1;i>=0;i--)
        {
            if(s2.empty()==true)
            {
                right.pb(pright);
                s2.push({a[i],i});
                continue;
            }
            while(s2.empty()==false&&s2.top().first>a[i])
                s2.pop();

            if(s2.empty()==true)
                right.pb(pright);
            else
                right.pb(s2.top().second);
            
            s2.push({a[i],i});
        }
        reverse(right.begin(),right.end());
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<" ";
        //cout<<endl;
        ll ans = 0, mod = 1e9 +7;
        for(int i = 0; i < a.size(); i++)
        {
          ans = (ans%mod + (a[i]*(long)(i-left[i])*(long)(right[i]-i)%mod))%mod;
        }
        return ans;
  }
};
