#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

head getnode(void){
    head p;
    p = (head)malloc(sizeof(struct node));
    return(p);
}

void createList(int n){
    head q;
    if (q == NULL){
        q->data = n;
        q->next = NULL;    
    }
}

void displayList(){
    head q;
    while(q != NULL){
        printf("%d",q->data);
        q->next;
    }
}

int main(){
    int n,da;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&da);
        createList(da);
        displayList();
    }
    return 0;
}