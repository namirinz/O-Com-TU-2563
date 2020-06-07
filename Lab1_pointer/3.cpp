#include <iostream>
using namespace std;
int main(){
    char c = 'Z';
    char *cp = &c;
    printf("cp is %p\n", cp);
    cout << "The character at cp is " << *cp << endl;

    cp += 1;
    printf("cp is %p\n", cp);
    cout << endl;
    int p = 3;
    int *intp = &p;
    printf("intp is %p\n", intp);
    cout << "The int at intp is " << *intp << endl;
    intp+= 1;
    printf("intp is %p\n", intp);
    cout << endl;

    double db = 1.123;
    double *dbp = &db;
    printf("intp is %p\n", dbp);
    cout << "The double at dbp is " << *dbp << endl;
    dbp++;
    printf("intp is %p\n", dbp);
    return 0;
}