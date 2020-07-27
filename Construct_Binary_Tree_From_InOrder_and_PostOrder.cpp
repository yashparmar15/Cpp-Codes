/*Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7*/
   
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
    TreeNode* buildUtil(vector<int>in, vector<int>post, int inStrt, 
                int inEnd, int* pIndex){ 
        if (inStrt > inEnd) 
            return NULL; 
        TreeNode* node = new TreeNode(post[*pIndex]); 
        (*pIndex)--; 
        if (inStrt == inEnd) 
            return node; 
        int iIndex = search(in, inStrt, inEnd, node->val); 
        node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
        node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 

        return node; 
    } 
    int search(vector<int> arr, int strt, int end, int value){ 
        int i; 
        for (i = strt; i <= end; i++) { 
            if (arr[i] == value) 
                break; 
        } 
        return i; 
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pIndex = inorder.size() - 1; 
        return buildUtil(inorder, postorder, 0, inorder.size() - 1, &pIndex);
    }
};
