//
//  main.cpp
//  linked-list-data-structures
//
//  Created by Jack Compton on 12/9/22.
//

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    void append(int x) {
        
        // creates a currNode pointer to add to linked list
        Node* currNode = new Node;
        currNode->data = x;
        currNode->next = NULL;

        // if list is empty add currNode to head and tail
        if (head == NULL) {
            head = currNode;
            tail = currNode;
        }
        
        // else point current tail to currNode and change new tail to new currNode
        else {
            tail->next = currNode;
            tail = tail->next;
        }
    }

    void prepend(int x) {
        Node* currNode = new Node;
        currNode->data = x;
        currNode->next = head;
        
        // if list is empty add currNode to head and tail
        if (head == NULL) {
            head = currNode;
            tail = currNode;
        }
        
        // else set the head of the list to currNode (currNode->next is set to the previous head on call)
        else {
            head = currNode;
        }
       
    }

    void find(int data) {
        Node* currNode = head;
        int i = 0;
        
        while (currNode != NULL) {
            
            if (currNode->data == data) {
                cout << data << " was found in the " << i << " position." << endl;
            }
            else {
                cout << data << " was not found in the list." << endl;
            }
            
            currNode = currNode->next;
            i += 1;
        }
    }

// user must view list before updating (add UI functions to control and create the linked lsit)
    void update(int pos, int data) {
        Node* currNode = head;
        int i = 0;
        
        while (currNode != NULL) {
            if (i == pos) {
                currNode->data = data;
            }
            else {
                cout << "Unable to update list." << endl;
            }
            
            currNode = currNode->next;
            i += 1;
        }
     }

    void print() {
        Node* currNode = head;
        
        while (currNode != NULL) {
            cout << currNode->data << "->";
            currNode = currNode->next;
        }
        cout << endl;
    }

    void reversal() {
        Node* curr = new Node();
        Node* prev = new Node();
        Node* next = new Node();
        
        curr = head;
        next = NULL;
        prev = NULL;
        
        while (curr != NULL) {
            // sets next to the current->next value
            next = curr->next;
            // sets the current->next pointer to prev
            curr->next = prev;
            // sets prev to the curr value (flips the original pointer to the previous value)
            prev = curr;
            // sets curr to the next value (traverses the list)
            curr = next;
        }
        head = prev;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue() {
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(int data) {
        Node* currNode = new Node;
        currNode->data = data;
        currNode->next = NULL;
        
        if (head == NULL) {
            head = currNode;
            tail = currNode;
        }
        else {
            tail->next = currNode;
            tail = tail->next;
        }
    }
        
    void pop(){
        cout << "Popped: " << head->data << endl;
            
        head = head->next;
        }
    
    void print(){
        Node* currNode = new Node;
        currNode = head;
        
        while (currNode != NULL) {
            cout << currNode->data << "->";
            currNode = currNode->next;
        }
        cout << endl;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    
    }
    
    void push(int data) {
        Node* currNode = new Node();
        currNode->data = data;
        
        if (top == NULL) {
            top = currNode;
            top->next = NULL;
        }
        else {
            currNode->next = top;
            top = currNode;
        }
    }
    
    void pop() {
        Node* temp = top;
        
        if (top == NULL) {
            cout << "This stack is empty." << endl;
        }
        else {
            cout << "Pop: " << top->data << endl;
            
            // sets the popped value to NULL (removes from the Stack)
            top = temp->next;
        }
    }
    
    void peek() {
        
        if (top == NULL) {
            cout << "This stack is empty." << endl;
        }
        else {
            cout << "Peek: " << top->data << endl;
        }
    }
    
    void print() {
        Node* temp = top;
        
        cout << "Printed stack: " << endl;
        
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    
    return 0;
}
