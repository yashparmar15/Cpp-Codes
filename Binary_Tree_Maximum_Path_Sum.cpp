/*Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42*/


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
    int recur(TreeNode* root , int &maxSum){
        if(!root)
            return 0;
        if(!root->left and !root->right){
            maxSum = max(maxSum,root->val);
            return root->val;
        }
        maxSum = max(maxSum,root->val);
        int left = recur(root->left,maxSum);
        int right = recur(root->right,maxSum);
        maxSum = max(maxSum,root->val + left);
        maxSum = max(maxSum,root->val + right);
        maxSum = max(maxSum , root->val + left + right);
        return max(left + root->val , max(root->val + right,root->val));
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return root->val;
        int maxSum = INT_MIN;
        recur(root,maxSum);
        return maxSum;
    }
};
