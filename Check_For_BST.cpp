bool check(Node* root){
    if(!root) return 1;
    if(root->left and root->data <= root->left->data) return 0;
    if(root->right and root->data >= root->right->data) return 0;
    if(root->left and root->left->right and root->left->right->data >= root->data) return 0;
    if(root->right and root->right->left and root->right->left->data <= root->data) return 0;
    return check(root->left) and check(root->right);
}


bool isBST(Node* root)
{
   if(!root) return 1;    
   if(root->left and root->data < root->left->data) return 0;
   if(root->right and root->data > root->right->data) return 0;
   return check(root); 
}
