// Input 2:
//     A = "aab"
    
// Output 2:
//     1

// Explanation 2:
//     Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
public:
    int dp[2002][2002];
    bool isPalidrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
            
    }
    int solve(string &s,int i,int j)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(isPalidrome(s,i,j))
            return dp[i][j] = 0;
        int ans = INT_MAX;
        for(int k = i; k <=j-1;k++)
        {
            int x=0,y=0;
            if(dp[i][k]!=-1)
            {
                x = dp[i][k];
            }
            else
            {
                x = solve(s,i,k);
                dp[i][k] = x;
            }
            
            if(dp[k+1][j]!=-1)
            {
                y = dp[k+1][j];
            }
            else
            {
                y = solve(s,k+1,j);
                dp[k+1][j] = y;
            }
            
            ans = min(ans,1+x+y);
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) 
    {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return solve(s,0,n-1); 
    }
};
//This one gives TLE in leetcode but will get accepted on IB.

//For leetcode

class Solution {
public:
    int dp[2001][2001];
    int dp2[2001][2001];
    bool ispalindrome(string &str,int i,int j)
    {
        if (i >= j) 
            return 1;
        if (dp2[i][j] != -1) 
            return dp2[i][j];
        
        if (str[i] == str[j]) 
            return dp2[i][j] = ispalindrome(str, i + 1, j - 1);
        
        return dp2[i][j] = 0;
    }
    
    int solve(string &str, int i, int j)
    {
        if(i>=j) 
            return 0;
        
        if(ispalindrome(str,i,j)) 
            return dp[i][j]=0;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        dp[i][j] = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            if(ispalindrome(str,i,k))
            {
               dp[i][j]=min(dp[i][j], solve(str,k+1,j)+1); 
            }                
        }
        return dp[i][j];
    }
    
    int minCut(string str)
    {
        int n = str.size();
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        return solve(str,0,n-1);
    }
};
