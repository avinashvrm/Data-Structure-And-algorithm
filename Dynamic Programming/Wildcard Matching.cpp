// Input: s = "adceb", p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

// i and j are the pointers of s and p resp.
// we know that if p[j]=='*' there can be multiple cases a) it can represent ''(empty substring) or seq of substring
// And also if we reach end of s but p isn't finished yet, it means p can have * at end as it can represent empty subs
class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<int>>& v)
    {
        if(i==s.size()&&j==p.size())
            return true;
      
        if(i==s.size()) 
            return (p[j]=='*'&& match(s,p,i,j+1,v));
      
        if(j==p.size())
            return false;
        
        if(v[i][j]!=-1) 
            return v[i][j];
        
        if(p[j]=='*')
            return v[i][j]= (match(s,p,i,j+1,v)||match(s,p,i+1,j,v));
        
        if(p[j]=='?'||s[i]==p[j])
            return v[i][j] = match(s,p,i+1,j+1,v);
        
        return false;
    }
    
    bool isMatch(string s, string p) 
    {
       vector<vector<int>> v(s.size(), vector<int>(p.size(), -1));  
       return match(s,p,0,0,v);
    }
};
