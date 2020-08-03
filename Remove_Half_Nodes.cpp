Node *RemoveHalfNodes(Node *root)
{
    if(!root)
        return NULL;
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if(root->left and !root->right)
        return root->left;
    if(root->right and !root->left)
        return root->right;
    return root;
}
