//https://leetcode.com/problems/longest-univalue-path/
class Solution {
public:
    int ans;
    int solve(TreeNode* root,int prev)
    {
        if(!root)
            return 0;
        if(root->val != prev)
            return 0;
        int left=0,right=0;
        if(root->left)
            left = solve(root->left,prev);
        if(root->right)
            right= solve(root->right,prev);
        return 1+max(left,right);
    }
    
    int longestUnivaluePath(TreeNode* root) 
    {
        if(!root)
            return 0;
        int l = solve(root->left,root->val);
        int r = solve(root->right,root->val);
        
        return max(l+r,max(longestUnivaluePath(root->left),longestUnivaluePath(root->right)));
    }
};
