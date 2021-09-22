
int solve(Node* root,int &mx)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data;
    
    int l = solve(root->left,mx);
    int r = solve(root->right,mx);
    
    if(root->left && root->right)
    {
        if(l+r+root->data > mx)
            mx = l+r+root->data;
        return max(l,r) + root->data;
    }
    else if(root->left)
    {
        return l+root->data;
    }
    else
    {
        return r+root->data;
    }
    
}
class Solution {
public:
    int maxPathSum(Node* root)
    {
        int maxsum = INT_MIN;
        int val=solve(root,maxsum);
        if(maxsum==INT_MIN){
            return val;
        }
        return maxsum;
    }
};
