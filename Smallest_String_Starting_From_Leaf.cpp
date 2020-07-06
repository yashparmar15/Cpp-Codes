// Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

// Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

// (As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

 

// Example 1:



// Input: [0,1,2,3,4,3,4]
// Output: "dba"
// Example 2:



// Input: [25,1,3,1,3,0,2]
// Output: "adz"
// Example 3:



// Input: [2,2,1,null,1,0,null,0]
// Output: "abc"
 

// Note:

// The number of nodes in the given tree will be between 1 and 8500.
// Each node in the tree will have a value between 0 and 25.




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
    void recur(vector<string> &v,TreeNode* root,string s){
        if(root == NULL)
            return;
        s = s + char(root->val + 'a');
        if(!root->left and !root->right){
            v.push_back(s);
            return;
        }
        recur(v,root->left,s);
        recur(v,root->right,s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v;
        string s = "";
        recur(v,root,s);
        for(int i = 0 ; i < v.size() ; i++){
            reverse(v[i].begin(),v[i].end());
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};