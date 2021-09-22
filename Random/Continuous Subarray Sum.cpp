class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n<2)
            return false;
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            sum = sum%k;
            if(sum==0 && i)
                return true;
            if(mp.find(sum%k)!=mp.end())
            {
                if(i - mp[sum] > 1)
                {
                    
                   // cout<<sum<<" "<<mp[sum];
                    return true;
                }
            }
            else
                mp[sum] = i;
        }
        return false;
    }
};
