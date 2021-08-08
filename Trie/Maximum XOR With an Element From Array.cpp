//https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
class Solution {
public:
    struct Trie
    {
        int val=0;
        Trie *child[2];
    };
    void insert(int x,Trie* root)
    {
        Trie *curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (x>>i) & 1;
            if(curr->child[bit]==NULL)
                curr->child[bit] = new Trie();
            
            curr=curr->child[bit];
        }
        curr->val = x;
    }
    int find(int x,Trie* root)
    {
        Trie *curr = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = (x>>i)&1;
            
            if(curr->child[!bit])
                curr = curr->child[!bit];
            else if(curr->child[bit])
                curr = curr->child[bit];
        }
        return curr->val;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = queries.size();
        vector<int> res(n,-1);
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(),[](vector<int> &a,vector<int>&b){
            return a[1] < b[1];
        });
        Trie* root = new Trie();
        sort(nums.begin(),nums.end());
        
        int i = 0;
        for(auto x : queries)
        {
            int val = x[0];
            int lim = x[1];
            int indx= x[2];
            
            while(i<nums.size() && nums[i] <= lim)
                insert(nums[i++],root);
            if(i>0)
            {
                int k = find(val,root);
                res[indx] = k^val;
            }
        }
        return res;
    }
};
