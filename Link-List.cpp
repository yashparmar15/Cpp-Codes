#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	string Name;
	int age;
	Node* next;
	Node(string name,int age){
		this->Name = name;
		this->age = age;
		next = NULL;
	}
};

Node* insertIntoList(Node* head,Node* temp){
	if(head->age > temp->age){
		temp->next = head;
		head = temp;
		return head;
	}
	Node* t = head;
	while(t->next != NULL){
		if(t->next->age > temp->age){
			temp->next = t->next;
			t->next = temp;
			return head;
		}
		t = t->next;
	}
	t->next = temp;
	return head;
}

void printLinkedList(Node* head){
	Node* t = head;
	while(t != NULL){
		cout << t->Name << " " << t->age << endl;
		t = t->next;
	}
	return;
}

int lengthofLinkedList(Node* head){
	int len = 0;
	Node* t = head;
	while(t != NULL){
		len++;
		t = t->next;
	}
	return len;
}

void printNthElement(Node* head,int N){
	int len = lengthofLinkedList(head);
	if(len < N) return;
	Node* t = head;
	while(t != NULL){
		N--;
		if(N == 0){
			cout << t->Name << " " << t->age << endl;
			break;
		}
		t = t->next;
	}
}

Node* removeNthElement(Node* head,int N){
	int len = lengthofLinkedList(head);
	if(len < N) return head;
	if(N == 1) return head->next;
	Node* t = head;
	while(t != NULL){
		N--;
		if(N == 1){
			t->next = t->next->next;
		}
		t = t->next;
	}
	return head;
}



int main(){
	string instruction;
	Node* head = NULL;
	while(true){
		cin >> instruction;
		if(instruction == "stop") break;
		if(instruction == "insert"){
			string name;
			int age;
			cin >> name >> age;
			if(head == NULL){
				head = new Node(name,age);
			} else {
				Node* temp = new Node(name,age);
				head = insertIntoList(head,temp);
			}
		}
		if(instruction == "print"){
			int num;
			cin >> num;
			printNthElement(head,num);
		}
		if(instruction == "remove"){
			int num;
			cin >> num;
			head = removeNthElement(head,num);
		}
		// printLinkedList(head);
	}
}