/*Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5*/


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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;   
        }
        if(head->next == NULL){
            if(head->val == val)
                return NULL;
            return head;
        }
        ListNode *ans = NULL;
        ListNode *temp = ans;
        ListNode *t = head;
        while(t != NULL){
            if(t->val != val){
                if(ans == NULL){
                    ans = temp = new ListNode(t->val);
                }
                else{
                    temp->next = new ListNode(t->val);
                    temp = temp->next;
                }
            }
            t = t->next;
        }
        return ans;
    }
};
