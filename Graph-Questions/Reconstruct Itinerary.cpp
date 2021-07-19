class Solution {    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        unordered_map<string,vector<string>> adj;
        vector<string> ans;
        //Make graph
        for(int i=0;i<tickets.size();++i)
            adj[tickets[i][0]].push_back(tickets[i][1]);
        
        for(auto it=adj.begin();it!=adj.end();it++)
            sort(it->second.begin(),it->second.end());
        stack<string> mystack;
        mystack.push("JFK");    //JFK is our fixed starting point
        while(!mystack.empty())
        {
            string src = mystack.top();
            if(adj[src].size()==0)  //No further travel possible
            {
                ans.push_back(src);
                mystack.pop();
            }
            else
            {
                auto dst = adj[src].begin();
                mystack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// static int fastio = []() {
//     #define endl '\n'
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(0);
//     return 0;
// }();
