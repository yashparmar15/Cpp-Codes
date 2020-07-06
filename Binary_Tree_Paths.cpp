// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3




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
    void recur(TreeNode *root , vector<int> temp , vector<string> &ans){
        if(!root)
            return;
        if(!root->left and !root->right){
            string t = "";
            for(int i = 0 ; i < temp.size(); i++){
                t = t + to_string(temp[i]) + "->";
            }
            t = t + to_string(root->val);
            ans.push_back(t);
            return;
        }
        temp.push_back(root->val);
        recur(root->left,temp,ans);
        recur(root->right,temp,ans);
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> temp;
        if(root == NULL)
            return ans;
        recur(root,temp,ans);
        return ans;
    }
};