// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.




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
    void recur(TreeNode* root , int &ans){
        if(!root)
            return;
        if(root->left and !root->left->left and !root->left->right)
            ans = ans + root->left->val;
        recur(root->left,ans);
        recur(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        recur(root,ans);
        return ans;
    }
};