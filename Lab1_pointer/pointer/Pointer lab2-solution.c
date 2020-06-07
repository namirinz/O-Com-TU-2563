// solution to pointer lab2


#include <stdio.h>
void foo1(int xval)
{
    int x;
    x = xval;
    
    /* print the address and value of x here */
    printf("Address of x is %p and Value of x is %d\n", &x,x);
    /* print the address and value of xval here */
    printf("Address of xval is %p and Value of xval is %d\n\n", &xval, xval);
}
void foo2(int dummy)
{
    int y;
    
    /* print the address and value of y here */
    printf("Address of y is %p and Value of y is %d\n", &y, y);
    /* print the address and value of dummy here */
    printf("Address of dummy is %p nd Value of dummy is %d\n\n", &dummy, dummy);
    
}

int main() {
    foo1(7);
    foo2(11);
    return 0;
}

