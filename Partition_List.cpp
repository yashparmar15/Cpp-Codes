/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5*/


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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        head = NULL;
        temp = head;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] < x){
                if(head == NULL)
                    head = temp = new ListNode(v[i]);
                else{
                    temp->next = new ListNode(v[i]);
                    temp = temp->next;
                }
            }
        }
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] >= x){
                if(head == NULL)
                    head = temp = new ListNode(v[i]);
                else{
                    temp->next = new ListNode(v[i]);
                    temp = temp->next;
                }
            }
        }
        return head;
    }
};
