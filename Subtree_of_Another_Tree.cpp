/*Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 *./
 
 
 
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
    bool check(TreeNode* s , TreeNode* t){
        if(!s and t) return false;
        if(s and !t) return false;
        if(s and t and s->val != t->val) return false;
        if(!s and !t)
            return true;
        return check(s->left,t->left) and check(s->right,t->right);
    }
    void recur(TreeNode* s,TreeNode* t,bool &ans){
        if(!s or ans)
            return;
        if(s->val == t->val and !ans)
            ans = check(t,s);
        recur(s->left,t,ans);
        recur(s->right,t,ans);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool ans = false;
        if(!s and !t)
            return 1;
        if(!s) return 0;
        if(!t) return 1;
        recur(s,t,ans);
        return ans;
    }
};
