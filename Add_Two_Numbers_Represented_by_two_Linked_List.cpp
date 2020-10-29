/*Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= N, M <= 5000*/

Node* reverseList(Node* head){
    Node* prev = NULL,*cur = head,*next = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first = reverseList(first);
    second = reverseList(second);
    int carry = 0;
    Node* temp1 = first,*temp2 = second;
    Node* ans = NULL,*temp = NULL;
    while(temp1 and temp2){
        int num = temp1->data + temp2->data + carry;
        if(num >= 10){
            carry = 1;
            num = num % 10;
        } else {
            carry = 0;
        }
        if(ans == NULL)
            ans = temp = new Node(num);
        else {
            temp->next = new Node(num);
            temp = temp->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1){
        int num = temp1->data + carry;
        if(num >= 10){
            carry = 1;
            num = num % 10;
        } else {
            carry = 0;
        }
        if(ans == NULL)
            ans = temp = new Node(num);
        else {
            temp->next = new Node(num);
            temp = temp->next;
        }
        temp1 = temp1->next;
    }
    while(temp2){
        int num = temp2->data + carry;
        if(num >= 10){
            carry = 1;
            num = num % 10;
        } else {
            carry = 0;
        }
        if(ans == NULL)
            ans = temp = new Node(num);
        else {
            temp->next = new Node(num);
            temp = temp->next;
        }
        temp2 = temp2->next;
    }
    if(carry == 1) temp->next = new Node(1);
    ans = reverseList(ans);
    return ans;
}
