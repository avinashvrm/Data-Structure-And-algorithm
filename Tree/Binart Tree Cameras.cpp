class Solution {
public:
    int cam;
    unordered_set<TreeNode*> s;
    int minCameraCover(TreeNode* root) 
    {
        cam = 0;
        if(!root)
            return cam;
        s.insert(NULL);//to start from second last level;
        dfs(root,NULL);
        return cam;
    }
    void dfs(TreeNode* root,TreeNode* parent)
    {
        if(root)
        {
            dfs(root->left,root);
            dfs(root->right,root);
            
            if(s.find(root->left)==s.end() || s.find(root->right)==s.end() ||(parent==NULL && s.find(root)==s.end()))
            {
                cam++;
                s.insert(root);
                s.insert(root->left);
                s.insert(root->right);
                s.insert(parent);
            }
        }
    }
};
