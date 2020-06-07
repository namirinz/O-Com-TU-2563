//circular liked
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
}struct node *head;

void createList(int n){
    struct node *p,*q;
    for (size_t i=1;i<=n;i++){
        p = (struct node*)malloc(sizeof(struct node));
        p->data = n;
        p->right = NULL;
        if (head == NULL){
            p->left = head;
            head = p;            
        }else {
            for(q = head; q->right != NULL;q= q->right);
            p->left = q;
            q->right = p;
        }
    }
}

int main(){
    int n;
    cin >> n;
    createList(n);
    return 0;
}