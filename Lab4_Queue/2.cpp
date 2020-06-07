#include <iostream>
#include <vector>
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
    p = front;
    if (front != NULL){
        front = front->next;
        return p->data;
    }
}

int main(){
    int num,x;
    vector<int> vii[10];
    for (size_t i=0;i<8;i++){
        cin >> num;
        vii[num%10].push_back(num);
    }
    for (size_t i=0;i<10;i++){
        for (auto k: vii[i]) enqueue(k);
        vii[i].clear();
    }
    while (front != NULL){
        x = dequeue();
        cout << x << " ";
        vii[x/10].push_back(x);
    } rear = NULL;
    for (size_t i=0;i<10;i++){
        for (auto k: vii[i]) enqueue(k);
    }cout << endl;
    while (front != NULL){
        x = dequeue();
        cout << x << " ";
    }

    return 0;
}