class Solution {
public:
    int dp[1001][1001];
    
    bool solve(string s1, string s2, string s3, int i, int j, int k)
    {                                                                                             //Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
                                                                                                  //Output: true
        if ((i == s1.size() && j == s2.size() && k == s3.size())) 
            return true;
        
        if (k == s3.size()) 
            return false;
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        if (s1[i] == s3[k] && solve(s1, s2, s3, i+1, j, k+1)) 
        {
            return dp[i][j] = true;
        }
        if (s2[j] == s3[k] && solve(s1, s2, s3, i, j+1, k+1))
        {
            return dp[i][j] = true;
        }
        
        return dp[i][j] = false;    
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        memset(dp, -1, sizeof dp);
        return solve(s1, s2, s3, 0, 0, 0);
    }
};
