class Solution 
{
    private:
    bool ValidIP(string s, int i,int j,int k)
    {
        int n = s.size();
       
        string a = s.substr(0,i+1);
        if(a.size()>3 || (a.size()==3 && a > "255") || (a.size()>1 && s[0]=='0'))
            return false;
        
        string b = s.substr(i+1,j-i);
        if(b.size()>3 || (b.size()==3 && b > "255") || (b.size()>1 && s[i+1]=='0'))
            return false;
        
        string c = s.substr(j+1,k-j);
        if(c.size()>3 || (c.size()==3 && c > "255") || (c.size()>1 && s[j+1]=='0'))
            return false;
        
        string d = s.substr(k+1,n-k-1);
        if(d.size()>3 || (d.size()==3 && d > "255") || (d.size()>1 && s[k+1]=='0'))
            return false;
        
        return true;
    }
public:
    vector<string> result;
    string solution;
    
    vector<string> restoreIpAddresses(string s) 
    {
        int n = s.size();
        if(n>12)
            return result;
        for(int i = 0; i<n-3; i++)
        {
            for(int j = i+1; j<n-2; j++)
            {
                for(int k = j+1; k<n-1; k++)
                {
                    if(ValidIP(s,i,j,k))
                    {
                        string solution = s.substr(0,i+1) + "." + s.substr(i+1,j-i) + "." + s.substr(j+1,k-j)
                            +"." + s.substr(k+1,n-k-1);
                        result.push_back(solution);
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
