class Solution {
public:
    void add_to_queue(string &w,unordered_set<string> &s,queue<string> &q)
    {
        int n = w.size();
        for(int i = 0;i<n;i++)
        {
            char c = w[i];
            for(char j = 'a';j<='z';j++)
            {
                if(j==c)
                    continue;
                w[i] = j;
                if(s.find(w)!=s.end())
                {
                    q.push(w);
                    s.erase(w);
                }
            }
            w[i] = c;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        
        if(s.find(endWord)==s.end() || beginWord==endWord)
            return 0;
        int ans = 1;
        
        q.push(beginWord);
        while(!q.empty())
        {
            int cnt = q.size();
            while(cnt--)
            {
                auto w = q.front();
                q.pop();
                if(w==endWord)
                    return ans;
                add_to_queue(w,s,q);
            }
            ans++;
        }
        return 0;
        
    }
};
