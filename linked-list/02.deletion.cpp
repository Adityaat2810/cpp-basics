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

class Deletion {
public:
    Node* deleteHead(Node* head) {
        if (!head) return nullptr; // empty list
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* deleteTail(Node* head) {
        if (!head) return nullptr;          // empty list
        if (!head->next) { delete head; return nullptr; } // single node case

        Node* temp = head;
        while (temp->next->next) { // stop at second last node
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }

    Node* deleteAtIndex(Node* head, int index) {
        if (!head) return nullptr;
        if (index == 0) return deleteHead(head);

        Node* temp = head;
        int i = 0;
        while (temp && temp->next && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (!temp || !temp->next) {
            cout << "Index out of bounds\n";
            return head;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;
    }

    Node* deleteByValue(Node* head, int value) {
        if (!head) return nullptr;

        if (head->data == value) {
            return deleteHead(head);
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Value not found\n";
            return head;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
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
    Deletion ops;
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List:\n";
    ops.printList(head);

    head = ops.deleteHead(head);
    cout << "\nAfter deleting head:\n";
    ops.printList(head);

    head = ops.deleteTail(head);
    cout << "\nAfter deleting tail:\n";
    ops.printList(head);

    head = ops.deleteAtIndex(head, 1);
    cout << "\nAfter deleting at index 1:\n";
    ops.printList(head);

    head = ops.deleteByValue(head, 20);
    cout << "\nAfter deleting value 20:\n";
    ops.printList(head);
}
