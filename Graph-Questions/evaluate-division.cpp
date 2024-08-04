https://leetcode.com/problems/evaluate-division/description/


This IMG will give clarity -> https://assets.leetcode.com/users/images/759de4ba-7588-4bd6-a2c6-918d36239324_1651291331.1632457.jpeg

/*  
    You will notice that this is a problem of graph (dfs)
    like if we are given a/b=2 and b/c=3
    then we can find a/c simply multiplying both the equations
    So if we create a graph
    Given- [[a,b],[b,c]]=[[2],[3]]
    We have to find [[a/c],[c/a]]
    a-->(b,2)
    b-->(a,1/2)
    b-->(a,1/2),(c,3)
    c-->(b,3/2)

    a/c=?
    then we will go from a->b res=2 * 1 =2
    now we will go from b->c res=2 * 3 =6
    res will be 6:

    c/a=?
    then we will go from c->b res=(1/3) * 1 =1/3
    now we will go from b->a res=(1/3) * (1/2) =1/6
    res will be 1/6:
*/
class Solution 
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        //we will be using unordered_map to store the data
        unordered_map<string,unordered_map<string,double>> adj;
        
        //create a adj list 
        createAdjList(adj,equations,values);
        
        vector<double> res(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> visited;
            double ans = -1.0;
            dfs(queries[i][0],queries[i][1],visited,adj,ans,1.0);
            res[i]= ans;
        }
        return res;   
    }
    void dfs(string start,string end,unordered_set<string>& visited,unordered_map<string,unordered_map<string,double>>& adj,double &ans,double temp)
    {
        //we cant find the  given string
        if(adj.find(start)==adj.end())
            return ;
        //if we have got our string end 
        if(start==end)
        {
            ans = temp;
            return;
        }
        visited.insert(start);
        //explore all possible paths 
        //if any one of them doesnot returns -1.0 we got our solution 
        for(auto i:adj[start])
        {
            //we dont want to revisit our previously visited strings
            if(!visited.count(i.first))
            {
                dfs(i.first,end,visited,adj,ans,i.second*temp);
            }       
        }
    }
    void createAdjList(unordered_map<string,unordered_map<string,double>>& adj,vector<vector<string>>&  equations,vector<double>& values)
    {
        for(int i=0;i<equations.size();i++)
        {
            string from=equations[i][0];
            string to=equations[i][1];
            adj[from].insert({to,values[i]});
            adj[to].insert({from,(double)1/values[i]});
        }
            
    }
};
