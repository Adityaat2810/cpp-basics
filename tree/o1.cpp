#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

void preOrder(Node * node){
    if(node == nullptr){
        return;
    }

    cout<<node->data<<"  ";
    preOrder(node->left);
    preOrder(node->right);

}

void postOrder(Node * node){
    if(node == nullptr){
        return;
    }


    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<"  ";

}

void inOrder(Node * node){
    if(node == nullptr){
        return;
    }


    inOrder(node->left);
    cout<<node->data<<"  ";
    inOrder(node->right);

}


int main(){
    cout<<"Hello, World!"<<endl;
    Node * root = new Node(1);

    root-> left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root-> right->left = new Node(6);
    root-> right->right = new Node(7);


    cout<<"Pre-order traversal"<<endl;
    preOrder(root);
    cout<<"\n";

    cout<<"In-order traversal"<<endl;
    inOrder(root);
    cout<<"\n";

    cout<<"Post-order traversal"<<endl;
    postOrder(root);
    cout<<"\n";


    cout<<"Tree Created!";


    return 0;
}