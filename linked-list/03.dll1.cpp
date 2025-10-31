#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data1) {
        this->data = data1;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* arrayToDll(vector<int> &arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* c = new Node(arr[i]);
        temp->next = c;
        c->prev = temp;
        temp = c;
    }

    return head;
}

void printDll(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

class Insertion {
public:
    Node* insertAtHead(Node* head, int data) {
        if (!head) return new Node(data);

        Node* n = new Node(data);
        n->next = head;
        head->prev = n;
        return n;
    }

    Node* insertAtTail(Node* head, int value) {
        Node* n = new Node(value);

        if (!head) return n;

        Node* temp = head;
        while (temp->next) temp = temp->next;

        temp->next = n;
        n->prev = temp;
        return head;
    }

    Node* insertAtIndex(Node* head, int index, int value) {
        if (index == 0) return insertAtHead(head, value);

        Node* temp = head;
        int i = 0;

        while (temp && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (!temp) {
            cout << "Index out of bound\n";
            return head;
        }

        Node* n = new Node(value);
        n->next = temp->next;
        n->prev = temp;

        if (temp->next) temp->next->prev = n;
        temp->next = n;

        return head;
    }
};

int main() {
    vector<int> arr = {10, 20, 30, 40};
    Node* head = arrayToDll(arr);

    Insertion ins;

    cout << "Initial ";
    printDll(head);

    head = ins.insertAtHead(head, 5);
    cout << "After insertAtHead(5): ";
    printDll(head);

    head = ins.insertAtTail(head, 50);
    cout << "After insertAtTail(50): ";
    printDll(head);

    head = ins.insertAtIndex(head, 3, 25);
    cout << "After insertAtIndex(3, 25): ";
    printDll(head);

    head = ins.insertAtIndex(head, 10, 999); // Out of bound
    return 0;
}
