/*Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.*/


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
    int count = 0;
    TreeNode* convertBST(vector<int> v,int start,int end){
        if(start > end) return nullptr;
        int mid = start + (end - start + 1) / 2;
        TreeNode* temp = new TreeNode(v[mid]);
        count++;
        temp->left = convertBST(v,start,mid - 1);
        temp->right = convertBST(v,mid + 1,end);
        return temp;
    }
    void inorder(vector<int> &v,TreeNode* root){
        if(!root) return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(v,root);
        TreeNode* ans;
        ans = convertBST(v,0,v.size() - 1);
        return ans;
    }
};
