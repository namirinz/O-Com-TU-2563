#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void createList(int num){
    struct node *p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = num;
    p->next = NULL;

    if (head == NULL) head = p;
    else {
        for (q=head;q->next != NULL; q = q->next);
        q->next = p;
    }
}
void displayList(){
    struct node *p;
    p = head;
    while(p != NULL){
        cout << "Data = " << p->data << endl;
        p = p->next;
    }cout << endl;
}
void deleteFront(){
    struct node *p;
    p = head;
    p = p->next;
    head = p;

    displayList();
}

void deleteLast(){
    
    struct node *p,*q;
    p = head;
    for (q=p->next; q->next !=  NULL; q=q->next,p=p->next);
    p->next = NULL;
    
    displayList();
}

void deleteMiddle(int pos){
    if (pos == 1) deleteFront();
    else {
        struct node *p,*q;
        p = head;
        for (q = p->next; pos > 2;pos--,q=q->next,p=p->next);
        p->next = q->next;
        q->next = NULL;
    }

    displayList();
}

int main(){
    int n,num;
    cout << "Input the number of nodes : ";
    cin >> n;
    for (size_t i=0;i<n;i++){
        cout << "Input data for node " << i+1 << " : ";
        cin >> num;
        createList(num);
    }
    displayList();
    
    deleteFront();
    deleteLast();
    cout << "Position to delete : ";
    cin >> num;
    deleteMiddle(num);

    return 0;
}