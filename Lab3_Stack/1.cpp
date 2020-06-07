#include <iostream>
using namespace std;

struct stack {
    int data;
    struct stack *next;
};
struct stack *top;


void push(int n){
    stack *p = new stack;

    p->data = n;
    p->next = top;
    top = p;
}
int pop(){
    int returnVal;
    if (top != NULL){
        returnVal = top->data;
        top = top->next;
    }
    return returnVal;
}
bool empty(){
    if (top == NULL) return true;
    else return false;
}

int main(){
    int n,x;
    while(true){
        cin >> x;
        if( x == -99) break;
        push(x);
    }
    while(!empty()) cout << pop() << " ";
    
    return 0;
}