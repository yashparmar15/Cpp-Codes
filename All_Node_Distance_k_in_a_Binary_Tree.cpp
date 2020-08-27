/*We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<int,bool> vis;
    void recur(TreeNode* root, unordered_map<int,vector<int>> &M){
        if(!root)
            return;
        if(root->left){
            M[root->val].push_back(root->left->val);
            M[root->left->val].push_back(root->val);
        }
        if(root->right){
            M[root->val].push_back(root->right->val);
            M[root->right->val].push_back(root->val);
        }
        recur(root->right,M);
        recur(root->left,M);
    }
    void dfs(unordered_map<int,vector<int>> M,int k,int target,int cur){
        if(cur == k and !vis[target])
            ans.push_back(target);
        if(cur > k)
            return;
        if(!vis[target]){
            vis[target] = 1;
            for(int i = 0 ; i < M[target].size() ; i++){
                if(!vis[M[target][i]])
                    dfs(M,k,M[target][i],cur + 1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int,vector<int>> M;
        if(!root)
            return {};
        recur(root,M);
        dfs(M,K,target->val,0);
        return ans;
    }
};
