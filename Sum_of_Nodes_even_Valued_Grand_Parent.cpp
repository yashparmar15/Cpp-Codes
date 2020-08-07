/*Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

 

Example 1:



Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.*/



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
    void recursion(TreeNode *root , int &count){
        if(root == NULL)
            return;
        if(root->val % 2 == 0){
            if(root->left != NULL and root->left->left != NULL)
                count += root->left->left->val;
            if(root->left != NULL and root->left->right != NULL)
                count += root->left->right->val;
            if(root->right != NULL and root->right->left != NULL)
                count += root->right->left->val;
            if(root->right != NULL and root->right->right != NULL)
                count += root->right->right->val;
        }
        recursion(root->left,count);
        recursion(root->right,count);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        int count = 0;
        recursion(root,count);
        return count;
    }
};
