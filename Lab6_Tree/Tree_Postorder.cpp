#include <iostream>
using namespace std;

struct node {
    char data;
    node *left;
    node *right;
}; typedef node* NodeTree;
NodeTree head = NULL;

void postorder(์NodeTree p){
    if (p != NULL){
        preorder(p->left);
        preorder(p->right);
        cout << p->data << " ";
    }
}

NodeTree makeTree(char dataNode){
    NodeTree p = new node;
    p->data = dataNode;
    p->left = NULL;
    p->right = NULL;
    if (head == NULL){
        head = p;
    }
    return(p);
}

void setLeft(NodeTree p,char dataNode){
    if (p == NULL) cout << "No Parent to insert";
    else if (p->left == NULL) cout << "Parent already has child";
    else {
        p->left = makeTree(dataNode);
    }
}

void setRight(NodeTree p,char dataNode){
    if (p == NULL) cout << "No Parent to insert";
    else if (p ->right == NULL) cout << "Parent already has child";
    else {
        p->right = makeTree(dataNode);
    }
}


int main(){
    return 0;
}