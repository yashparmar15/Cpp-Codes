/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.*/


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
    ListNode* reverse(ListNode* root,int k){
        ListNode* temp = root,*prev = NULL,*next = NULL;
        while(temp != NULL and k--){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* root = new ListNode(0,head);
        ListNode* cur = head;
        ListNode* prev = root;
        while(cur != NULL){
            ListNode* tail = cur;
            int index = 0;
            while(cur != NULL and index < k){
                index++;
                cur = cur->next;
            }
            if(index != k){
                prev->next = tail;
            } else {
                prev->next = reverse(tail,k);
                prev = tail;
            }
        }
        return root->next;
    }
};
