// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
 

// But the following [1,2,2,null,3,null,3] is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3



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
    bool isSymmetric2(TreeNode *root1,TreeNode *root2)
        {
if(root1==NULL&&root2==NULL) return true;
        if(root1==NULL||root2==NULL)
            return false;
        return (root1->val==root2->val) && isSymmetric2(root1->left,root2->right) && isSymmetric2(root1->right,root2->left);
        
      }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {return true;}
        else
        {
            return isSymmetric2(root,root);
        }
    }
};