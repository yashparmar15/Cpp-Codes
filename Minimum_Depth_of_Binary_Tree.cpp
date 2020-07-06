// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.




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
    void recur(vector<int> temp , TreeNode* root,int &Min){
        if(!root)
            return;
        if(!root->left and !root->right){
            if(temp.size() + 1 < Min)
                Min = temp.size() + 1;
            return;
        }
        temp.push_back(root->val);
        recur(temp,root->left,Min);
        recur(temp,root->right,Min);
        temp.pop_back();
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> temp;
        int Min = INT_MAX;
        recur(temp,root,Min);
        return Min;
    }
};