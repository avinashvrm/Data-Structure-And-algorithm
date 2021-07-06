// A building can expand only when a neighbouring buildings have heights greater than or equal height as curr building.
// So in order to find how much a building can expand we have to find the index of Nearest Smaller to left and right and expandable width = NSR - NSL
// Therefor to find Area, we just mutiply with height and return the maxmum one.
// To find NSR and NSL we use stack of pair(for storing index)
typedef vector<int> vi;
#define pb push_back
class Solution {
public:
    int largestRectangleArea(vector<int>& a) 
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
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            width.pb((right[i]-left[i])-1);
            area.pb(width[i]*a[i]);
        }
        // for(int i=0;i<n;i++)
        //     cout<<width[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<area[i]<<" ";
        // cout<<endl;
        return *max_element(area.begin(),area.end());
    }
};
