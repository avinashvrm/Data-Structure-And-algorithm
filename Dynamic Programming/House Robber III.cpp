class Solution {
public:
    unordered_map<TreeNode*,int> mp;
    int solve(TreeNode *root)
    {
        if(!root)
            return 0;
        
        if(mp.find(root)!=mp.end())
            return mp[root];
        
        int sum = 0;
        if(root->left)
            sum+=solve(root->left->left) + solve(root->left->right);
        if(root->right)
            sum+= solve(root->right->left) + solve(root->right->right);
        
        int inl = root->val + sum;
        
        int exl = solve(root->left) + solve(root->right);
        
        mp[root] = max(inl,exl);
        
        return mp[root];
    }
    int rob(TreeNode* root) 
    {
         if(!root)
             return 0;
        return solve(root);
    }
};
