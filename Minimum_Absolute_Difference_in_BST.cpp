// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).




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
     void recur(TreeNode* root,vector<int> &v){
        if(!root)
            return;
        v.push_back(root->val);
        recur(root->left,v);
        recur(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        recur(root,v);
        sort(v.begin(),v.end());
        int minDiff = INT_MAX;
        for(int i = 0 ; i < v.size() - 1 ; i++){
            minDiff = min(minDiff,v[i + 1] - v[i]);
        }
        return minDiff;
    }
};