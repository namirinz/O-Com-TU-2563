#include <iostream>
using namespace std;

int mem[1000000];
int fib(int n){
    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;
    for (int i=2;i<=n;i++){
        mem[i] = mem[i-1]+mem[i-2];
    }
    return mem[n];
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}