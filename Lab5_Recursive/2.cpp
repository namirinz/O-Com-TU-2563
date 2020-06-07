#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
}; node *head = NULL,*tail;


int size = 0;

void createList(int n){
    node *p = new node;
    node *q = new node;
    p->data = n;
    p->next = tail;

    if ( head == NULL ){
        head = p;
    }else {
        for (q=head; q->next != tail; q=q->next);
        q->next = p;
    }
}

node* rec2(node *p){
    if (p->next == NULL) return p;
    return p->next;
}

node* rec1(node *tur,node *rab){
    if (rab->next == tail){
        tail = rab;
        rab->next = NULL; 
        tur->next = NULL;
        return(head,head->next);
    }if (rab->next == NULL){
        node *back = rec2(tail);
        back->next = tur;
        return(head,head->next);
    }
    if (head != NULL) return (rec1(tur->next,rab->next));
}

int displayList(){
    node *p = new node;
    p = head;
    int i=1;
    while (p != tail){
        cout << "Data : " << p->data << endl;
        p = p->next;
        i++;
    }
    return i;
}
void displayList2(){
    node *p = new node;
    p = tail;
    while ( p!= NULL){
        cout << "Data : " << p->data << endl;
        p = p->next;
    }
}

int main(){
    int n,num;
    cin >> n;
    for (size_t i=0;i<n;i++){
        cin >> num;
        createList(num);
    }
    displayList();
    rec1(head,head->next);
    displayList2();
    return 0;
}