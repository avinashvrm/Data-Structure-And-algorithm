typedef vector<int> vi;
#define pb push_back
class Solution {
public:
    int MAH(vector<int>& a) 
    {
        int n = a.size();  
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
        // for(int i=0;i<n;i++)
        //     cout<<left[i]<<" ";
        //cout<<endl;
        vi right,width;
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
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<" ";
        // cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            width.pb((right[i]-left[i])-1);
            int area = width[i]*a[i];
            ans = max(ans,area);
        }
        // for(int i=0;i<n;i++)
        //     cout<<width[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<area[i]<<" ";
        // cout<<endl;
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& grid) 
    {
        if(grid.size()==0)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        
    
        vector<int> ar(m);
	    for(int i=0;i<m;i++)
        {
            ar[i]=grid[0][i]-'0';
        }
        int maxarea = MAH(ar);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='0')
                    ar[j]=0;
                else
                    ar[j]=ar[j]+grid[i][j]-'0';
            }
            maxarea=max(maxarea,MAH(ar));
        }
        return maxarea;
    }
};
