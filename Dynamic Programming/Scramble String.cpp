class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string a, string b)
    {
        if(a==b)
            return true;
        
        //if(s1.size() != s2.size()) return false;
        
        string key = "";
        key = a + "#$#" + b;
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        int n = a.size();
        int flag = false;
        for(int i=1; i<n; i++)
        {
            bool op1 = solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));// if swapping would have done
            bool op2 = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));//if swapping  wouldn't have done
            if(op1 || op2)
            {
                flag = true;
                break;
            }
            
        }
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) 
    {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2)
            return false;
        if(n1==1)
            return s1==s2;
        return solve(s1,s2);
    }
};
