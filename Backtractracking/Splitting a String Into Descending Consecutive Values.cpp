//https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
class Solution {
public:
    bool dfs(string s,long long val)
    {
        if(stoull(s)==val)
            return true;
        for(int i =1;i<s.size();i++)
        {
            long long  tar = stoull(s.substr(0,i));
            if(tar!=val)
                continue;
            if(dfs(s.substr(i),tar-1))
                return true;
        }
        return false;
    }
    bool splitString(string s) 
    {
        int n = s.size();
        for(int i =1;i<n;i++)
        {
            string temp = s.substr(0,i);
            long long val = stoull(temp);
            if(dfs(s.substr(i),val-1))
                return true;
        }
        return false;
    }
};
