#include <iostream>
using namespace std;
int arr[1000001];

int rec(int n){
    int mem[n+1];
    mem[0] = 0;
    int max1,max2 = 1;
    for (int i=1;i<=n;i++){
        max1 = 0;
        for (int j=1;j<i;j++){
            if ( arr[j] <= arr[i]){
                max1 = max(max1,mem[j]);
            }
        }
        mem[i] = max1+1;
        max2 = max(mem[i],max2);
    }
    return max2;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&arr[i]);
    printf("%d",n-rec(n));
    return 0;
}