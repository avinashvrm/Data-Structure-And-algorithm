class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        int cnt=0;
        unordered_map<int,int>mp;
        for(auto u:A)
            for(auto v:B)
                mp[u+v]++;

        for(auto u:C)
        {
            for(auto v:D)
            {
                auto it = mp.find(0-u-v);
                if(it != mp.end())
                    cnt += it->second;
            }
        }
        return cnt;
    }
};
