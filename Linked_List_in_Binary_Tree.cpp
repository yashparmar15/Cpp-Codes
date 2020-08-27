/*Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:



Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
Example 2:



Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 

Constraints:

1 <= node.val <= 100 for each node in the linked list and binary tree.
The given linked list will contain between 1 and 100 nodes.
The given binary tree will contain between 1 and 2500 nodes.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void recur(TreeNode* root,vector<int> temp,vector<vector<int>> &paths){
        if(!root)
            return;
        temp.push_back(root->val);
        if(!root->left and !root->right){
            paths.push_back(temp);
        }
        recur(root->left,temp,paths);
        recur(root->right,temp,paths);
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> paths;
        vector<int> temp;
        recur(root,temp,paths);
        vector<int> list;
        ListNode* t = head;
        while(t != NULL){
            list.push_back(t->val);
            t = t->next;
        }
        for(int i = paths.size() - 1 ; i >= 0 ; i--){
            if(paths[i].size() >= list.size()){
                for(int j = 0 ; j <= paths[i].size() - list.size() ; j++){
                    bool flag = true;
                    if(paths[i][j] == list[0] and paths[i][j + list.size() - 1] == list[list.size() - 1]){
                        for(int k = 0 ; k < list.size() ; k++){
                            if(paths[i][j + k] != list[k]){
                                flag = false;
                                break;
                            }
                        }
                        if(flag) return true;
                    }
                }
            }
        }
        return false;
    }
};
