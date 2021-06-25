// Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.
// Input: s = "abcbdd"
// Output: true
// Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
class Solution {
public:
    int memo_palindrome[2001][2001];
    bool palindrome(int i,int j,string& s)
    {
        if(i>=j)
            return true;
        else if(memo_palindrome[i][j]!=-1)
            return memo_palindrome[i][j];
        else
        {
            if(s[i]==s[j])
                return memo_palindrome[i][j]=palindrome(i+1,j-1,s);
            else 
                return memo_palindrome[i][j]=false;
        }
    }
    int memo[2001][2001];
    bool solve(int i,string& s,int count)
    {
        if(i>=s.length())
        {
            if(count==3)
                return true;
            else 
                return false;
        }
        if(count>=3)
            return false;
        
        if(memo[i][count]!=-1)
            return memo[i][count];
        
        bool q=false;
        for(int j=i;j<s.length();++j)
        {
            if(palindrome(i,j,s))
            {
                q = q || solve(j+1,s,count+1);
                if(q)
                    break;
            }
        }
        return memo[i][count] = q;
        
    }
    bool checkPartitioning(string& s) 
    {
        int n=s.length();
        memset(memo,-1,sizeof(memo));
        memset(memo_palindrome,-1,sizeof(memo_palindrome));
        return solve(0,s,0);
    }
};
