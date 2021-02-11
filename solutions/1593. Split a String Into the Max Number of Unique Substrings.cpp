class Solution {
public:
    int ans = 0;
    unordered_set<string> st;
    
    void blow_back(string s,int l,int n)
    {
        
        if(st.size()>ans)
                ans = st.size();
        if(l>=n)
            return;
        string c = "";
        for(int i = l;i<n;i++)
        {
            c = c+s[i];
            if(st.find(c)==st.end())
            {
                st.insert(c);
                blow_back(s,i+1,n);
                st.erase(c);
            }
        }
    }
    int maxUniqueSplit(string s) 
    {
        int n = s.size();
        blow_back(s,0,n);
        return ans;
    }
};
