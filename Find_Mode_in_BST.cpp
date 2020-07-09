// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// For example:
// Given BST [1,null,2,2],

//    1
//     \
//      2
//     /
//    2
 

// return [2].

// Note: If a tree has more than one mode, you can return them in any order.




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
    void recur(vector<int> &inorder,TreeNode* root){
        if(!root)
            return;
        recur(inorder,root->left);
        inorder.push_back(root->val);
        recur(inorder,root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> inorder;
        recur(inorder,root);
        unordered_map<int,int> M;
        int Max = INT_MIN;
        for(int i = 0 ; i < inorder.size() ; i++){
            M[inorder[i]]++;
            Max = max(M[inorder[i]],Max);
        }
        vector<int> ans;
        for(auto t:M){
            if(t.second == Max)
                ans.push_back(t.first);
        }
        return ans;
    }
};