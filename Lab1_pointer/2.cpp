#include <iostream>
using namespace std;
#include <stdio.h>
void foo1(int xval)
{
    int x;
    x = xval;
/* print the address and value of x here */
    cout << "Address of x is " << &x << "and Value of x is " << x << endl;
/* print the address and value of xval here */
    cout << "Address of xval is " << &xval << "and Value of xval is " << xval << endl;
}
void foo2(int dummy)
{
    int y;
    /* print the address and value of y here */
    cout << "Address of y is " << &y << "and Value of x is " << y << endl;
    
    /* print the address and value of dummy here */
    cout << "Address of x is " << &dummy << "and Value of x is " << dummy << endl;

}
int main() {
    foo1(7);
    cout << endl;
    foo2(11);
    return 0;
}