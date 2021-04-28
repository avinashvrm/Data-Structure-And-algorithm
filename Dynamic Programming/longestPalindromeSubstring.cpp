class Solution {
public:
    string longestPalindrome(string text1) 
    {
        int n = text1.size();
        string text2;
        text2 = text1;
        reverse(text2.begin(),text2.end());
        int t[n+1][n+1];
        int res = 0;
        string ans = "";
        for(int i = 0;i<=n ;i++)
        {
            for(int j = 0; j<=n; j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                    if(t[i][j] > res)
                    {
                        string temp = text1.substr(i-t[i][j],t[i][j]);
                        string revtemp = temp;
                        reverse(revtemp.begin(),revtemp.end());
                        
                        if(revtemp==temp)
                        {
                            res=t[i][j];
                            ans=temp;
                        }
                    }
                }
                else
                    t[i][j] = 0;
            }
        }
        return ans;
        
     }
};
