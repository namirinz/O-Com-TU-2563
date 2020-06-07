#include <stdio.h>
int main(){
    char n[1];
    FILE *fptr = fopen("student.txt","r");
    fscanf(fptr, "%[^\n]",n);
    printf("%c",n[0]);
    printf("%d",int(n[0]));
    fclose(fptr);
    //for (int i=0;i<int(n);i++)
    return 0;
}