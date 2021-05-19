class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), [](string a, string b) {
            if(a.length() == b.length())
                return a>b;
            else
                return a.length() < b.length();
        });
        
        unordered_map<string,int> mp;
        
        mp[words[0]] = 1;
        int res = 1;
        for(int i = 1;i<words.size();i++)
        {   
            mp[words[i]] = 1;
            for(int j = 0;j<words[i].size();j++)
            {
                string s = words[i];
                s.erase(s.begin()+j);
                if(mp[s])
                {
                    cout<<"here"<<"  ";
                    mp[words[i]] = max(mp[words[i]],mp[s] + 1);
                }
            }
            res = max(res,mp[words[i]]);
        }
        
        return res;
    }
};
