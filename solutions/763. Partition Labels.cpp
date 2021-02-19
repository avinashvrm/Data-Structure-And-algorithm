class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        vector<int> end(26,0);
        int n = S.size()-1;
        for(int i=0;i<=n;i++)
            end[S[i]-'a'] = i;
        
        vector<int> v;
        int st = 0,en = end[S[0]-'a'];
        for(int i=0;i<=n;i++)
        {
            en = max(en,end[S[i]-'a']);
            
            if(i==en)
            {
                v.push_back(i - st + 1);
                st = i+1;
            }
        }
        return v;
        
    }
};
