/*
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
Example 2:

Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
Example 3:

Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.*/



#define ll long long
class Solution {
public:
    int n,m;
    ll dp[501][501];
    ll solve(vector<int>& nums1, vector<int>& nums2,int i,int j)
    {
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        ll res = 0;
        res = (ll)nums1[i]*(ll)nums2[j] + solve(nums1,nums2,i+1,j+1);
        res = max(res,solve(nums1,nums2,i+1,j));
        res = max(res,solve(nums1,nums2,i,j+1));
        return dp[i][j] = res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        n = nums1.size();
        m = nums2.size();
        memset(dp,-1,sizeof(dp));
        ll res = solve(nums1,nums2,0,0);
        if(res == 0)
        {
            int mx1 = INT_MIN, mn1 = INT_MAX;
            for(int i=0;i<n;i++) 
            {
                if(nums1[i] == 0) 
                    return 0;
                mx1 = max(mx1,nums1[i]);
                mn1 = min(mn1,nums1[i]);
            }
            int mx2 = INT_MIN, mn2 = INT_MAX;
            for(auto i:nums2) 
            {
                if(i == 0)
                    return 0;
                mx2 = max(mx2,i);
                mn2 = min(i,mn2);
            }
            return max(mx1*mn2, mx2*mn1);
        }
        return res;
    }
};
