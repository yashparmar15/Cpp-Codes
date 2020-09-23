Node* reverseDLL(Node * head)
{
    //Your code here
    Node* cur = head,*prev = NULL,*next = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->prev = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
