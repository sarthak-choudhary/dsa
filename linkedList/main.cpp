#include <iostream>
#include "linkedList.h"

using namespace std;


void print(Node* head) {
    while (head != nullptr) {
        cout << head -> data << " " ;
        head = head -> next;
    }

    cout << endl;
}

Node* takeInput() {
    int data {};
    cin >> data;
    Node* head {nullptr};
    Node* currentNode {nullptr};

    while (data != -1) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            currentNode = newNode;
        } else {
            currentNode -> next = newNode;
            currentNode = currentNode -> next;
        }

        cin >> data;
    }

    return head;
}

Node* deleteNode(Node *head, int i) {

    Node* temp = head;
    Node* idleNode = nullptr;
    int count {};
    
    if (i == 0) {
        Node* newHead = temp -> next;
        delete temp;
        return newHead;
        
    }
    
    while (temp != nullptr && count < i -1) {
        temp = temp -> next;
        count++;
    }
    
    if (temp != nullptr ) {
    	idleNode = temp -> next;
    	temp -> next = idleNode -> next;
        delete idleNode;
        
        return head;
    }
    
    return head;
	    
}

Node* insertNode(Node* head, int i, int data) {
    if (i == 0) {
        Node* newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }

    Node* temp = head;
    int count {};
    while (temp != nullptr && count < i - 1) {
        temp = temp -> next;
        count++;
    }

    if (temp != nullptr) {
        Node* newNode = new Node(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;

        return head;
    }

    cout << "Incorrect information" << endl;
    return head;

}


int main() {
    Node* head;

    head = takeInput();
    print(head);
    head = deleteNode(head, 5);
    print(head);
}