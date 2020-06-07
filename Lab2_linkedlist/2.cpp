#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
//Declare "head" node that global variable
struct node*head = NULL; 

void createList(int num){
    struct node*p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = num;
    p->next = NULL;

    if (head == NULL){
        head = p;
    }else {
        for (q=head; q->next != NULL; q = q->next);
        q->next = p;
    }
}

void displayList(){
    struct node *p;
    p = head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

void insertFront(int n){
    struct node*p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = n;
    p->next = head;
    head = p;
}

void insertLast(int n){
    struct node*p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL;
    for (q = head; q->next != NULL ;q = q->next);
    q->next = p;
}

void insertMiddle(int n){
    int pos;
    cout << "Input Position : "; cin >> pos;
    struct node *p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL;
    for (q=head; pos > 2; q = q->next,pos--);
    p->next = q->next;
    q->next = p;

}

int main(){
    int n,num;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> num;
        createList(num);
    }
    displayList();
    cout << endl;
    
    int num1; cout << "Front : ";
    cin >> num1;
    insertFront(num1);
    displayList();
    cout << endl;

    cout << "Last :"; cin >> num1;
    insertLast(num1);
    displayList();
    cout << endl;

    cout << "Middle : "; cin >> num1;
    insertMiddle(num1);
    displayList();
    cout << endl;
    return 0;
}