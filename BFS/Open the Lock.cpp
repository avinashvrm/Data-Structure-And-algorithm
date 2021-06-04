class Solution {
public:
    vector<string> add_in_q(string key) 
    {
        vector<string> res;
        for (int i = 0 ; i < 4; i++) 
        {
            string tmp = key;
            
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
         }
        return res;
    }
    int openLock(vector<string>& deadend, string target)
    {
        string st = "0000";
        unordered_set<string> dead(deadend.begin(),deadend.end());
        unordered_set<string> vis;
        if(target==st)
            return 0;
        if(dead.find(st)!=dead.end())
            return -1;
        
        queue<string> q;
        q.push(st);
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string temp = q.front();
                q.pop();
                
                vector<string> nei = add_in_q(temp);
                for(auto x : nei)
                {
                    if(temp==target)
                        return ans;
                    if(vis.find(x)!=vis.end())
                        continue;
                    if(dead.find(x)==dead.end())
                    {
                        vis.insert(x);
                        q.push(x);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
