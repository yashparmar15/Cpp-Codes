/*Given a binary tree root, a ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right then move to the right child of the current node otherwise move to the left child.
Change the direction from right to left or right to left.
Repeat the second and third step until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:



Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:



Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0
 

Constraints:

Each tree has at most 50000 nodes..
Each node's value is between [1, 100].*/

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
    unordered_map<TreeNode*,int> M;
    int count(TreeNode* root,bool temp){
        if(!root)
            return 0;
        if(M.count(root))
            return M[root];
        if(temp)
            return M[root->right] = count(root->right,0) + 1;
        else
           return M[root->left] = count(root->left,1) + 1;
    }
    void recur(TreeNode* root, int &ans){
        if(!root)
            return;
        int left = count(root->left,1);
        int right = count(root->right,0);
        M[root->left] = left;
        M[root->right] = right;
        ans = max(ans,max(left,right));
        recur(root->left,ans);
        recur(root->right,ans);
    }
    int longestZigZag(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        recur(root,ans);
        return ans;
    }
};
