/*
Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

Example 1:
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

Example 2:
Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.
*/
class Solution {
public:
    int solve(vector<int>&nums,int x,int y)
    {
        int n=nums.size();
        vector<int>dp1(n,0),dp2(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i<x)
            {
                sum+=nums[i];
                dp1[i]=sum;
            }
            else
            {
                sum=sum+nums[i]-nums[i-x];
                dp1[i]=max(dp1[i-1],sum);
            }
        }
         sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+y>n-1)
            {
                sum+=nums[i];
                dp2[i]=sum;
            }
            else
            {
                sum=sum+nums[i]-nums[i+y];
                dp2[i]=max(dp2[i+1],sum);
            }
        }
        int ans=0;
        for(int i=x-1;i<n-y;i++)
        {
            ans=max(ans,dp1[i]+dp2[i+1]);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int n1, int n2) 
    {
        return max(solve(nums,n1,n2),solve(nums,n2,n1));
    }
};
