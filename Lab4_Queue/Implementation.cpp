#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
}; typedef node* Node;
Node front = NULL,rear = NULL;



void enqueue(int num){
    Node p = new node;
    p->data = num;
    p->next = NULL;
    if (rear == NULL){
        front = p;
    }else {
        rear->next = p;
    }
    rear = p;
}

int dequeue(){
    Node p = new node;
    if (front != NULL){
        p = front;
        front = front->next;
        return p->data;
    }else {
        cout << "There are not anything in here";
    }
}

int main(){
    int n,num;
    cin >> n;
    for (size_t i=0;i<n;i++){
        cin >> num;
        enqueue(num);
    }
    int x;
    while (front != NULL){
         x = dequeue();
         cout << x << endl;
    }
    return 0;
}