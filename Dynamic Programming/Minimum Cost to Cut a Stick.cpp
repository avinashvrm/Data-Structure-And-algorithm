/*Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). 
Return the minimum total cost of the cuts.
  
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. 
The second cut is done to a rod of length 6 (i.e. the second part of the first cut), 
the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).*/ 


class Solution {
public:
    int solve(vector<int> &cuts,int st_i,int en_i,int startValue,int endValue,vector<vector<int>> &dp)
    {
        if(st_i>en_i)
            return 0;
        
        if(dp[st_i][en_i]!=-1)
            return dp[st_i][en_i];
        
        int res = INT_MAX;
        int curr_cost = endValue - startValue;
        for(int k = st_i;k<=en_i;k++)
        {
            int first_half = solve(cuts,st_i,k-1,startValue,cuts[k],dp);
            int second_half = solve(cuts,k+1,en_i,cuts[k],endValue,dp);
            
            int temp = curr_cost + first_half + second_half;
            
            res = min(res,temp);
        }
        return dp[st_i][en_i] = res;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(cuts,0,m-1,0,n,dp);
        
    }
};
