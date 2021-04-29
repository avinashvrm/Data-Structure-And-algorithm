class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto &x : strs)
        {
            string s = x;
            sort(s.begin(),s.end());
            mp[s].push_back(x);
        }
        
        int n = mp.size();
        vector<string> v;
        
        for(auto &x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
        
        
    }
};
