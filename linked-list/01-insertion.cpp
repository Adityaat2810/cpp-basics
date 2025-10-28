#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

class Insertion {
public:

    Node* insertAtHead(int value, Node* head) {
        Node* newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node* insertAtTail(int value, Node* head) {
        Node* newNode = new Node(value);
        if (!head) return newNode;

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
        return head;
    }

    // Insert at a specific index (0-based)
    Node* insertAtIndex(int value, Node* head, int index) {
        if (index == 0) {
            return insertAtHead(value, head);
        }

        Node* temp = head;
        int i = 0;
        while (temp && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (!temp) {
            cout << "Index out of bounds\n";
            return head;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    Node* insertAfterNum(int num, int value, Node* head) {
        Node* temp = head;
        while (temp && temp->data != num) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Number not found\n";
            return head;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    void printList(Node* head) {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Insertion listOps;
    Node* head = nullptr;

    head = listOps.insertAtHead(10, head);
    listOps.printList(head);

    head = listOps.insertAtTail(20, head);
    listOps.printList(head);

    head = listOps.insertAtTail(30, head);
    listOps.printList(head);

    head = listOps.insertAtIndex(15, head, 1);
    listOps.printList(head);

    head = listOps.insertAfterNum(20, 25, head);
    listOps.printList(head);


    listOps.printList(head);
}
