class Solution {
public:
    bool f(vector<int>& pos, int m,int mid)
    {
        int placed = 1, last_pos = pos[0];
        
        for(int i = 1;i<pos.size();i++)
        {
            if(pos[i] - last_pos>=mid)
            {
                last_pos = pos[i];
                placed++;
            }
        }
        return placed>=m;
    }
    int maxDistance(vector<int>& pos, int m) 
    {
        int n = pos.size();
        sort(pos.begin(),pos.end());
        int l = 0;
        int h = pos[n-1];
        int ans = 0;
        while(l<=h)
        {
            int mid = (l+h)/2;
            
            if(f(pos,m,mid))
            {
                ans = max(ans,mid);
                l = mid+1;
            }
            else
                h=mid-1;
        }
        return ans;
    }
};
