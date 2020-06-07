// Solution to pointer exercise 1

#include <stdio.h>

int main() {
    int in = 5;
    double db = 10.5;
    char ch = 'C';
    
    int *p = &in;
    double *q = &db;
    char *s = &ch;
    
    printf("Value of int is %d\n", in);
    printf("Address of int is %p \n", p);
    printf("Size of of int is %lu bytes\n", sizeof(in));
    printf("Size of of pinter to int is %lu bytes\n\n", sizeof(p));
    
    printf("Value of double is %f\n", db);
    printf("Address of double is %p \n", q);
    printf("Size of of double is %lu bytes\n", sizeof(double));
    printf("Size of of pinter to double is %lu bytes\n\n", sizeof(q));
    
    printf("Value of char is %c\n", ch);
    printf("Address of char is %p \n", s);
    printf("Size of of char is %lu bytes\n", sizeof(ch));
    printf("Size of of pinter to char is %lu bytes\n\n", sizeof(s));
    
    return 0;
}

