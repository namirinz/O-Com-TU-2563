// Solution to pointer lab 3

#include <stdio.h>

int main() 
{
    char c = 'Z';
    char *cp = &c; 
    printf("cp is %p\n", cp); 
    printf("The character at cp is %c\n",*cp);
    
    /* see what cp+1 is */
    
    cp = cp+1;
    printf("cp is %p\n\n", cp);
    
    /* Do not print *cp, because it points to memory not allocated to your program */
    
    int i = 15;
    int *intp = &i; 
    printf("intp is %p\n", intp); 
    printf("The int at intp is %d\n",*intp);
    
    /* see what intp+1 is */
    
    intp = intp+1;
    printf("intp is %p\n\n", intp);
    
    /* Do not print *intp, because it points to memory not allocated to your program */
    
    double db = 12.48;
    double *dbp = &db; 
    printf("dbp is %p\n", dbp); 
    printf("The double at dbp is %f\n",*dbp);
    
    /* see what intp+1 is */
    
    dbp = dbp+1;
    printf("dbp is %p\n\n", dbp);
    
    /* Do not print *dbp, because it points to memory not allocated to your program */
    
    
    
    
    return 0;
}

