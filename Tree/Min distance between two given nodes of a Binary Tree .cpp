int dis(Node* temp,int a,int d)
{
    if(temp==NULL)  return -1;
    if(temp->data==a)
        return d;
    int x = dis(temp->left,a,d+1);
    int y = dis(temp->right,a,d+1);
    return max(x,y);
}
Node *lca(Node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==n1 || root->data==n2)
        return root;
    
    Node *l = lca(root->left,n1,n2);
    Node *r = lca(root->right,n1,n2);
    
    if(l && r)
        return root;
    if(l==NULL)
        return r;
    else 
        return l;
}
int findDist(Node* root, int a, int b) 
{
    Node *la = lca(root,a,b);
    return dis(la,a,0) + dis(la,b,0);
    
}
