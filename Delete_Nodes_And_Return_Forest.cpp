/*Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]*/


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
    
    TreeNode* recur(TreeNode* root , unordered_map<int,bool> &M , vector<TreeNode*> &ans){
        if(!root)
            return NULL;
        root->left = recur(root->left,M,ans);
        root->right = recur(root->right,M,ans);
        if(M[root->val]){
            if(root->left and !M[root->left->val])
                ans.push_back(root->left);
            if(root->right and !M[root->right->val])
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& v) {
        vector<TreeNode*> ans;
        unordered_map<int,bool> M;
        for(int i = 0 ; i < v.size() ; i++){
            M[v[i]] = 1; 
        }
        recur(root,M,ans);
        if(root and !M[root->val])
            ans.push_back(root);
        return ans;
    }
};
