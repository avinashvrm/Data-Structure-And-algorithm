/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

Example 1:
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.



Sort the elements and now you just need to do one way. At every step you need to make a choice between : 1. picking the element or 2. skipping the element.
Do this with memoization. Cheers!
*/class Solution {
public:
    int dp[20001];
    int n;
    int solve(vector<int> &nums,int i)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int elem = nums[i];
        int sum = 0;
        int nextIndex = i;
        //summing the duplicates of the element
        while(nextIndex < n &&  nums[nextIndex]==elem)
        {
            nextIndex++;
            sum+=elem;
        }
        //skipping the elem+1 elements
        while(nextIndex < n && nums[nextIndex]==(elem+1)){
            nextIndex++;
        }
        // either you pick or you skip
        int op1 = sum + solve(nums,nextIndex);
        int op2 = solve(nums,i+1);
        return dp[i] = max(op1,op2);
        
    }
    int deleteAndEarn(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        return solve(nums,0);
    }
};
