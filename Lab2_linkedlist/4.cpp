#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void displayList(){
    struct node *p;
    p = head;
    while (p != NULL){
        cout << "Data : ";
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

void createList(int num){
    struct node *p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = num;
    p->next = NULL;

    if (head == NULL) head = p;
    else {
        for (q=head;q->next != NULL; q=q->next);
        q->next = p;
    }
}

void searchList(int n){
    struct node *p;
    p = head;
    int i;
    for (i=1;p->data != n;p=p->next,i++);
    cout << "Data found at node " << i;
}

int main(){
    int n,num;
    cout << "Input number of nodes : ";
    cin >> n;

    for (size_t i=0;i<n;i++){
        cout << "Input data to node " << i+1 << " : ";
        cin >> num;
        createList(num);
    }displayList();

    cout << "Input the element to be search : ";
    cin >> num;
    searchList(num);
    return 0;
}