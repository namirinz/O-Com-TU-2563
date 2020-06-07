#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;


void createList(int n){
    int num;
    struct node*p,*q;
    for (int i=0;i<n;i++){
        cout << "Input data for node " << i+1 << " : ";
        cin >> num;
        p = (struct node*)malloc(sizeof(struct node));
        p->data = num;
        p->next = NULL;
        if (head == NULL){
            head = p;
        }        
        else {
            for (q = head; q->next != NULL; q = q->next); //วิ่งไปจนถึงท้าย แล้วค่อยต่อ
            q->next = p;
        }
    }
}
void displayList(){
    cout << "Data entered in the list : " << endl;
    struct node*q;
    q = head;
    while(q != NULL){
        cout << "Data = " << q->data << endl;
        q = q->next;
    }
}

int main(){
    int n;
    cout << "Input the number of nodes: ";
    cin >> n;
    createList(n);
    displayList();
    cout << head->data << " " << head->next->data;
    return 0;
}