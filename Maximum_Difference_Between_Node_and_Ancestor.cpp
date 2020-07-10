// Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

// (A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

// Example 1:



// Input: [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: 
// We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 

// Note:

// The number of nodes in the tree is between 2 and 5000.
// Each node will have value between 0 and 100000.



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
    void help(TreeNode* root,int min,int max,int& ans){
        if(root==NULL)  return ;
        min=std::min(min,root->val);
        max=std::max(max,root->val);
        ans=std::max(ans,abs(min-max));
        
        help(root->left,min,max,ans);
        help(root->right,min,max,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        if(root==NULL)  return 0;
        int min=root->val,max=root->val;
        help(root,min,max,ans);
        return ans;
    }
};