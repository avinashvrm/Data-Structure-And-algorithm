class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int> ioc;
        vector<int> v;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==c)
                ioc.push_back(i);
        }
        int l = 0;
        int r = 0;
        for(int i = 0;i<s.size();i++)
        {
            
            if(i>ioc[r])
            {
                l = r;
                if(r<ioc.size()-1)
                    ++r;
            }
            v.push_back(min(abs(i-ioc[l]),abs(i-ioc[r])));
       }
        return v;
        
    }
};
