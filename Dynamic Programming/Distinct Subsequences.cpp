/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the
remaining characters' relative positions.(i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
*/



class Solution {
public:
    unsigned long long dp[1005][1005];
    unsigned long long solve(string &s, string &t,int i,int j)
    {
        if(j>=t.size())
            return 1;
        if(i>=s.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        unsigned long long cnt = 0;
        if(s[i]==t[j])
            cnt+= solve(s,t,i+1,j+1) + solve(s,t,i+1,j);
        else
            cnt+= solve(s,t,i+1,j);
        
        return dp[i][j] = cnt;
    }
    int numDistinct(string s, string t) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};
