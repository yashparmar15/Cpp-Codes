/*Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:



Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:



Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
Example 3:

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
Example 4:

Input: root = [1,1]
Output: 1
 

Constraints:

Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].*/


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
    int M = 1000000007;
    int findsum(TreeNode* root){
        if(!root)
            return 0;
        int left = findsum(root->left);
        int right = findsum(root->right);
        return left + right + root->val;
    }
    int recur(TreeNode* root, long long int &ans,long long int totalsum){
        if(!root)
            return 0;
        int left = recur(root->left,ans,totalsum);
        int right = recur(root->right,ans,totalsum);
        int sum = left + right + root->val;
        ans = max(ans,(totalsum - sum) * sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        long long int totalsum = findsum(root);
        long long int ans = 0;
        recur(root,ans,totalsum);
        return ans % (int)(1e9 + 7);
    }
};
