// Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



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
    void recur(TreeNode* root , vector<int> &v){
        if(!root)
            return;
        if(!root->left and !root->right){
            v.push_back(root->val);
            return;
        }
        recur(root->left,v);
        recur(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        recur(root1,v1);
        vector<int> v2;
        recur(root2,v2);
        if(v1.size() != v2.size())
            return 0;
        for(int i = 0 ; i < v1.size() ; i++){
            if(v1[i] != v2[i])
                return 0;
        }
        return 1;
    }
};