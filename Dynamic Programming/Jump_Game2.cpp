class Solution {
public:
    int dp[1101];
    int solve(vector<int>&nums,int st)
    {
        if(st>=nums.size()-1)
            return 0;
        
        if(dp[st]!=NULL)
            return dp[st];
        int min_jump = INT_MAX-1;
        for(int i = st + 1; i<=st + nums[st]; i++)
        {
            min_jump = min(min_jump,1 + solve(nums,i));
        }
        return dp[st] = min_jump;
    }
    int jump(vector<int>& nums) 
    {
        return solve(nums,0);  
    }
}

// O(n) solution
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int jump = 0;
        int curr_max = 0;
        int next_max = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            curr_max = max(curr_max,i+nums[i]);
            
            if(i==next_max)
            {
                jump++;
                next_max = curr_max;
            }
            
        }
        return jump;
    }
};
