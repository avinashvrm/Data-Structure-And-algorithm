// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest nodes of the tree.
// Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
// Example 2:

// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree.
// Example 3:

// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

class Solution {
public:
    int solve(TreeNode* root,int d,int &mxd,TreeNode* &res)
    {
        if(!root)
            return d-1;
        if(d > mxd)
            mxd = d;
        int l = solve(root->left, d+1,mxd,res);
        int r = solve(root->right,d+1,mxd,res);
        
        if(l==mxd && r==mxd)
        {
            res = root;
        }
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        TreeNode *res = NULL;
        int mxd = 0;
        solve(root,0,mxd,res);
        return res;
    }
};
