/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9*/



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
    vector<int> dfs(TreeNode* root){
        if(!root)
            return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        vector<int> res(2,0);
        res[0] = max(left[0],left[1]) + max(right[0],right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res[0],res[1]);
    }
};



////////////////////////////////////////////////////////



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
    unordered_map<TreeNode*,unordered_map<int,int>> M;
    int dfs(TreeNode* root,int picked){
        if(!root) return 0;
        if(M[root][picked]) return M[root][picked];
        int temp = 0;
        if(picked)
            temp = max(temp,dfs(root->right,0) + dfs(root->left,0));
        else {
            temp = max(temp,dfs(root->right,1) + dfs(root->left,1) + root->val);
            temp = max(temp,dfs(root->right,0) + dfs(root->left,0));
        }
        return M[root][picked] = temp;
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        return dfs(root,0);
    }
};
