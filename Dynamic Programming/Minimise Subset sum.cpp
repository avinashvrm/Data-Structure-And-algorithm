/*SAME PROBLEM(bas puchne ka tarika dusra h)
https://leetcode.com/problems/last-stone-weight-ii/

So, if you look the problem carefully you will find this is the problem of minimum subset sum difference, if you can't, I'll show you how.
See the main line is that we have to store the value y-x where y and x are the weights of any two choosen stones.
And if the weights are same both the stones will be destroyed, 
this sums up the problem as we have two divide the array stones in two subsets in such a way that the difference between the sums of the subsets should be minimum.

*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int range=0, n=stones.size();
        for(int i=0; i<n; i++){
            range += stones[i];
        }
        int sum=range/2;
        bool dp[n+1][sum+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        int max=0;
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-stones[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
                
                if(i==n && dp[i][j]==true)
                    max=j;
            }
        }
//         vector<int> temp;
//         for(int j=0; j<=sum; j++){
//             {
//                 temp.push_back(j);
//             }
//         }
//         int max = *max_element(temp.begin(),temp.end());
        
        int res = range - (2*max);
        return res;
    }
};
