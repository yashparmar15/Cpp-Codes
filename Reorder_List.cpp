/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.*/


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
    
    ListNode* reverse(ListNode* head){
        ListNode *cur , *next , *prev;
        cur = head;
        prev = NULL;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    ListNode* merge(ListNode* head1 , ListNode* head2){
        ListNode *t1 , *t2;
        t1 = head1;
        t2 = head1;
        bool flag = true;
        head1 = head1->next;
        while(head1 and head2){
            if(flag){
                t1->next = head2;
                head2 = head2->next;
                t1 = t1->next;
                flag = !flag;
            } else {
                t1->next = head1;
                head1 = head1->next;
                t1 = t1->next;
                flag = !flag;
            }
        }
        if(head1) t1->next = head1;
        else t1->next = head2;
        return t2;
    }
    
    void reorderList(ListNode* head) {
        ListNode *t1,*t2;
        t1 = head;
        t2 = head;
        if(!head or !head->next or !head->next->next)
            return;
        while(t1->next != NULL and t2->next != NULL){
            t1 = t1->next;
            if(t2->next->next)
                t2 = t2->next->next;
            else
                t2 = t2->next;
        }
        t2 = reverse(t1->next);
        t1->next = NULL;
        head = merge(head,t2);
    }
};
