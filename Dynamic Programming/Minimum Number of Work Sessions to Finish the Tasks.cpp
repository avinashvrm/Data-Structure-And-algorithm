//https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
// Go to the link and prectice once, dp with bit masking question, you were clueless on the first go!,so plz revise

class Solution {
public:
    long long dp[1<<15][180];
    int find(vector<int>&nums,int mask,int sum,int se,int n)
    {
        if(mask==(1<<n)-1)// iska matlb sare n-1 places are filled with one,i.e all the given tasks are completed
        {
            //cout<<mask<<"   "<<(1<<n)-1<<endl;
            return 1;
        }
        int ans=INT_MAX;
        if(dp[mask][sum]!=-1)
        {
            return dp[mask][sum];
        }
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))==0)
            {
                if(sum+nums[i]>se)
                {
                    ans=min(ans,1+find(nums,mask|(1<<i),nums[i],se,n));
                }
                else
                {
                    ans=min(ans,find(nums,mask|(1<<i),sum+nums[i],se,n));
                }
            }
        }
        return dp[mask][sum]=ans;
    }
    int minSessions(vector<int>&nums, int se)
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,0,se,nums.size());
    }
};
