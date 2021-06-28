/*//https://leetcode.com/problems/maximum-alternating-subsequence-sum/
The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
[1,2,3]--3(taking only 3)

 - At a each given index, we can either choose this element and call the next index with an opposite sign.
 - Or we can not choose this element and call the next index with the same sign as the one which was passed to current index.
 - The answer now will simply be the max of these returned two values.
 - We use isPos to signify isPositive sign, which, if false, will mean that sign is negative.
 */
class Solution {
public:
    long long dp[2][100001];
    long long solve(int i, vector<int>&nums, bool isPos)
    {   
        if(i>=nums.size())
            return 0;
        if(dp[isPos][i]!=-1)
            return dp[isPos][i];
        
        long long curr = (isPos ? nums[i] : -1*nums[i]);
        
        return dp[isPos][i] = max(curr + solve(i+1, nums, !isPos), solve(i+1, nums, isPos));
    }
    long long maxAlternatingSum(vector<int>& nums) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, true);
    }
};
