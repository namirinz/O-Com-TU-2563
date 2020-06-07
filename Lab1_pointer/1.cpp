#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    double x = 5.1231;
    int y = 2;
    char s = 'a';
    
    double *px;
    px = &x;

    char *ps;
    ps = &s;
    
    int *py;
    py = &y;
    
    cout << "Value of int is " << y << endl;
    cout << "Address of int is "; printf("%p\n",py);
    cout << "Size of of int is " << sizeof(y) << endl;
    cout << "Size of of pinter to int is "; printf("%lu\n",sizeof(py));
    cout << endl;
    cout << "Value of double is " << *px << endl;
    cout << "Address of double is "; printf("%p\n",px);
    cout << "Size of of double is " << sizeof(x) << endl;
    cout << "Size of of pinter to double is " << sizeof(*px) << endl;
    cout << endl;
        cout << "Value of char is " << *ps << endl;
    cout << "Address of char is "; printf("%p\n",ps);
    cout << "Size of of char is " << sizeof(s) << endl;
    cout << "Size of of pinter to char is " << sizeof(*ps) << endl;
    

}