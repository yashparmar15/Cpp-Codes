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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            if(temp->left)
                s.push(temp->left);
            else {
                while(!s.empty()){
                    TreeNode* t1 = s.top();
                    s.pop();
                    ans.push_back(t1->val);
                    if(t1->right){
                        s.push(t1->right);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
