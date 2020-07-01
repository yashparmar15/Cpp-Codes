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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        head = NULL;
        temp = head;
        for(int i = 0 ; i < v.size() ; i++){
            if(head == NULL){
                temp = head = new ListNode(v[i]);
            } else {
                ListNode* t  = new ListNode(v[i]);
                temp->next = t;
                temp = temp->next;
            }
        }
        return head;
    }
};