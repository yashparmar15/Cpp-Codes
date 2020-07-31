/*Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 

Constraints:

The number of nodes in the tree is between 1 and 100.
Each node will have value between 0 and 100.
The given tree is a binary search tree.*/



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
    void recur(TreeNode* root,unordered_map<int,int> &M){
        if(!root)
            return;
        root->val = M[root->val];
        recur(root->left,M);
        recur(root->right,M);
    }
    void inorder(TreeNode* root,vector<int> &v){
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        unordered_map<int,int> M;
        vector<int> v;
        inorder(root,v);
        int total = 0;
        for(int i = 0 ; i < v.size() ; i++){
            total = total + v[i];
        }
        for(int i = 0 ; i < v.size() ; i++){
            M[v[i]] = total;
            total = total - v[i];
        }
        recur(root,M);
        return root;
    }
};
