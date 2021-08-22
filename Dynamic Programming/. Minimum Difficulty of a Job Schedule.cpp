/*Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
  
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
*/
class Solution {
public:
    int n,maxVal = 1e7;;
    int solve(vector<int>& jobd, int indx,int d,vector<vector<int>> &dp)
    { 
        if(indx==n && d==0)
            return 0;
        
        if(d<0 || indx>=n)
        {
            return maxVal;
        }
        if(dp[indx][d]!=-1)
            return dp[indx][d];
        
        int work = 0;
        int res = maxVal;
        for(int i=indx;i<n;i++)
        {
            work = max(work,jobd[i]);
            
            res = min(res,work + solve(jobd,i+1,d-1,dp));
            //cout<<res<<"  ";
        }
        return dp[indx][d] = res;
        
    }
    int minDifficulty(vector<int>& jobd, int d) 
    {
        n = jobd.size();
        if(n<d)
            return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return solve(jobd,0,d,dp);
    }
};
