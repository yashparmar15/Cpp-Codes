// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7


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
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int start, int end, int& root) {
        if(start>end) return NULL;
        int mid = start;
        for(int i=start;i<=end;i++) {
            if(preorder[root] == inorder[i]){
                mid = i;
                break;
            }
        }
        return new TreeNode(preorder[root++],
                            buildTreeUtil(preorder, inorder, start, mid-1, root),
                            buildTreeUtil(preorder, inorder, mid+1, end, root));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = 0;
        return buildTreeUtil(preorder, inorder, 0, preorder.size()-1, root);
    }
};