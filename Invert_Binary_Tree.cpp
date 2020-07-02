// Invert a binary tree.

// Example:

// Input:

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Output:

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recur(TreeNode* root){
        if(root == NULL)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        recur(root->left);
        recur(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        recur(root);
        return root;
    }
};