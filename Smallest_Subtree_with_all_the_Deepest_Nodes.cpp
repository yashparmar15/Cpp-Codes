/*iven a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:



We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.
 

Note:

The number of nodes in the tree will be between 1 and 500.
The values of each node are unique.*/



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
    TreeNode* ans = NULL;
    int size = 0;
    int recur(TreeNode* root , unordered_map<TreeNode*,bool> &M){
        if(!root or ans != NULL)
            return 0;
        int count = 0;
        if(!root->left and !root->right){
            if(M[root]){
                count ++;
                M[root] = 0;
            }
            bool flag = true;
            for(auto m : M){
                if(m.second){
                    flag = false;
                    break;
                }
            }
            if(flag and ans == NULL and size == 1){
                ans = root;
            }
        }
        int left = recur(root->left,M);
        int right = recur(root->right,M);
        bool flag = true;
        for(auto m : M){
            if(m.second){
                flag = false;
                return left + right + count;
            }
        }
        if(flag and ans == NULL and left + right == size){
            ans = root;
        }
        return left + right + count;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return NULL;
        if(!root->left and !root->right)
            return root;
        vector<TreeNode*> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            temp.clear();
            while(s--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        unordered_map<TreeNode*,bool> M;
        for(auto t : temp)
            M[t] = 1;
        size = M.size();
        recur(root,M);
        return ans;
    }
};
