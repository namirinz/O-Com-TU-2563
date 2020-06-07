#include <iostream>
using namespace std;
// 0 = 48
int main(){
    char n[1];
    FILE *fptr = fopen("student.txt","r");
    fscanf(fptr, "%[^\n]",n);
    printf("%c\n",n[0]);
    char s[n[0]-48][2][100] = {{"John",'1'},{"Zebbra",'2'},{"Asssv",'3'}};
    char team[n[0]-48][2];
    for (int i=0;i<n[0]-48;i++){
        fscanf(fptr, "%s %c",&s[i][0],&s[i][1]);

        cout << team << " " << s[i] 
    }
    return 0;
}