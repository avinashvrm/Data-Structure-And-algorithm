class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* root, int &ans)
    {
        if(!root) 
            return 0;
        int l=dfs(root->left,ans);
        int r=dfs(root->right,ans);
        
        int st_path = max(root->val,root->val + max(l,r));
        int case2 = max(st_path,root->val+l+r);
        ans=max(ans, case2);
        return st_path;
    }
};
