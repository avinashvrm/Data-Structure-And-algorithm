
#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        ll res = 0;
        int n = nums.size();
        vector<unordered_map<ll,ll>> mp(n);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll diff = (ll)nums[i] - (ll)nums[j];
                if(mp[j].find(diff)!=mp[j].end())
                {
                    mp[i][diff]+=(mp[j][diff]+1);
                    res+=mp[j][diff];
                }
                else
                    mp[i][diff]+=1;
            }
        }
        return res;
    }
};
