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
        if(head == NULL)
            return NULL;
        while(head->val == val){
            if(head->next == NULL)
                return NULL;
            head = head->next;
        }
        ListNode* temp = head->next, *t =head;
        while(temp != NULL){
            if(temp->val == val){
                if(temp->next == NULL)
                    t->next = NULL;
                else
                    t->next = temp->next;
                temp = temp->next;
            }
            else{
                temp = temp->next;
                t = t->next;
            }
        }
        return head;
    }
};
