// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
  
//  Input: nums = [1,2,3]  Output: [1,2] 
//  Input: nums = [1,2,4,8]  Output: [1,2,4,8]
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1)
            return nums;
        int lis = 1;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        for(int i =1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i] <= dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    lis = max(dp[i],lis);
                }     
            }
        }
        vector<int> res;
        int prev = -1;
        for(int i=n-1;i>=0;i--)
        {
            //cout<<dp[n-i-1]<<" ";
            if(dp[i]==lis && (prev % nums[i]==0 || prev==-1))
            {
                lis--;
                res.push_back(nums[i]);
                prev = nums[i];
            }
        }
        return res;
        
        
    }
};
