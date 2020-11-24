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
    TreeNode* dfs(vector<int> &v,int start,int end){
        if(start > end) return NULL;
        int mid = (start + end + 1) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = dfs(v,start,mid - 1);
        root->right = dfs(v,mid + 1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        if(v.size() == 0) return NULL;
        return dfs(v,0,v.size() - 1);
    }
};
