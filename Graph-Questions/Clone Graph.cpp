/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    void dfs(Node* u, unordered_map<Node*,Node*>& mp)
    {   
        Node* u_copy = new Node(u->val);
        
        mp.insert({u,u_copy});
        for(auto v: u->neighbors)
        {
            if(mp.find(v) == mp.end()){
                dfs(v,mp);
            }
        }       
    }
    
    void addEdges( unordered_map<Node*,Node*>& mp)
    {       
        for(auto u: mp)// iterate through map
        {
            for(auto v: u.first->neighbors) // iterate through neighbours
            {
                u.second->neighbors.push_back(mp[v]);//add the neighbors to copy node neighbors vector 
            }
        }
    }
    Node* cloneGraph(Node* node) {
        
        if(node ==NULL)
            return NULL;
        unordered_map<Node*,Node*> mp;
        // apply the dfs
        dfs(node,mp);
        addEdges(mp);//Linking Process
        
        return mp[node]; // mp[node] contains the reference of copy_node
    }
};


// BFS
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(node == NULL)
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> Q;
        Q.push(node);
        
        visited[node] = new Node(node->val);
        while(!Q.empty())
        {
            int n = Q.size();
            Node* curr = Q.front();
            Q.pop();
            for(auto nei: curr->neighbors)
            {
                if(!visited[nei])
                {
                     visited[nei] = new Node(nei->val);
                     Q.push(nei);
                }
                visited[curr]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];

    }
};
