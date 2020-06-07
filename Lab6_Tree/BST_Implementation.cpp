#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> vi;

struct node {
    int data;
    node* left;
    node* right;
}; typedef node* Node;
Node head = NULL;

Node makeNode(int dataNode){
    Node p = new node;
    p->data = dataNode;
    p->left = NULL;
    p->right = NULL;
    if (head == NULL){
        head = p; 
    }
    return(p);
}

void inorder(Node p){
    if (p != NULL){
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void setLeft(Node p,int dataNode){
    Node q = makeNode(dataNode);
    p->left = q;
}

void setRight(Node p,int dataNode){
    Node q = makeNode(dataNode);
    p->right = q;
}

//head->left , dataNode
void buildTree(Node p,int dataNode){
    if (p == NULL) head = makeNode(dataNode);
    else {
        if (dataNode < p->data){
            if (p->left == NULL){
                setLeft(p,dataNode);
            }else {
                buildTree(p->left,dataNode);
            }
        }else if (dataNode > p->data){
            if (p->right == NULL){
                setRight(p,dataNode);
            }else {
                buildTree(p->right,dataNode);
            }
        }
    }
}

int main(){
    int num;
    for (size_t i=0;i<15;i++){
        cin >> num;
        buildTree(head,num);
    }
    inorder(head);
    return 0;
}