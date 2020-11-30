/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.*/


class Node{
public:
    int val;
    Node* next;
    Node(int v){
        this->val = v;
        next = NULL;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    Node* head = NULL;
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int len = 0;
        Node* t = head;
        while(t != NULL){
            len++;
            t = t->next;
        }
        if(index >= len) return -1;
        t = head;
        while(t != NULL){
            if(index == 0) return t->val;
            index--;
            t = t->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(head == NULL){
            head = new Node(val);
            return;
        }
        Node* t = new Node(val);
        t->next = head;
        head = t;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    Node* addt(int val){
        if(head == NULL){
            head = new Node(val);
            return head;
        }
        Node* t = head;
        while(t->next != NULL){
            t = t->next;
        }
        Node* temp = new Node(val);
        t->next = temp;
        return head;
    }
    void addAtTail(int val) {
        head = addt(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int len = 0;
        Node* t = head;
        while(t != NULL){
            len++;
            t = t->next;
        }
        if(index > len) return;
        t = head;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == len) {
            addAtTail(val);
            return;
        }
        while(t->next != NULL){
            if(index == 1){
                Node* temp = new Node(val);
                temp->next = t->next;
                t->next = temp;
                return;
            }
            index--;
            t = t->next;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int len = 0;
        Node* t = head;
        while(t != NULL){
            len++;
            t = t->next;
        }
        if(index >= len) return;
        if(index == 0) {
            Node* temp = head->next;
            head = temp;
            return;
        }
        t = head;
        while(t->next != NULL){
            if(index == 1){
                t->next = t->next->next;
                return;
            }
            t = t->next;
            index--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
