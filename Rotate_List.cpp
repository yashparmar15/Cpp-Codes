class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL|| head->next==NULL)
            return head;
        ListNode* temp=head;
        int n=1;
        while(temp->next!=NULL)
        {
            n++;
            temp=temp->next;
        }
        if(k%n==0)
            return head;
        int rot=k%n;
        rot=(n-rot);
        
        ListNode* temp1=head;
        for(int i=1;i<rot;i++)
            temp1=temp1->next;
        ListNode* newhead=temp1->next;
        temp1->next=NULL;
        temp = newhead;
        while(temp != NULL){
            if(temp->next == NULL){
                temp->next = head;
                break;
            }
            temp = temp->next;
        }        
        return newhead;
    }
};
