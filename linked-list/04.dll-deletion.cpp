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
    cout << "List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

class Deletion {
public:
    Node* deleteAtHead(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
        head = head->next;

        if (head) head->prev = nullptr;
        delete temp;
        return head;
    }

    Node* deleteAtTail(Node* head) {
        if (!head) return nullptr;
        if (!head->next) {
            delete head;
            return nullptr;
        }

        Node* temp = head;
        while (temp->next) temp = temp->next;

        temp->prev->next = nullptr;
        delete temp;
        return head;
    }

    Node* deleteAtIndex(Node* head, int index) {
        if (!head) return nullptr;
        if (index == 0) return deleteAtHead(head);

        Node* temp = head;
        int i = 0;
        while (temp && i < index) {
            temp = temp->next;
            i++;
        }

        if (!temp) {
            cout << "Index out of bound\n";
            return head;
        }

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;

        delete temp;
        return head;
    }
};

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = arrayToDll(arr);

    cout << "Initial ";
    printDll(head);

    Deletion del;

    head = del.deleteAtHead(head);
    cout << "After deleteAtHead(): ";
    printDll(head);

    head = del.deleteAtTail(head);
    cout << "After deleteAtTail(): ";
    printDll(head);

    head = del.deleteAtIndex(head, 1);
    cout << "After deleteAtIndex(1): ";
    printDll(head);

    head = del.deleteAtIndex(head, 10);
    return 0;
}
