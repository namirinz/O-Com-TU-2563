//Longest Increasing Subsequence
#include <iostream>
using namespace std;
int n,arr[1000000];

int rec(int range){
    int mem[range+1];
    int max1,max2 = 0;
    for (int i1=1;i1<=range;i1++){
        max1 = 0;
        for (int j1=1;j1<i1;j1++){
            if (arr[j1] <= arr[i1]){
                max1 = max(max1,mem[j1]);
            }
        }
        mem[i1] = max1+1;
        max2 = max(mem[i1],max2);
        }
    return max2;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&arr[i]);
    printf("%d ", rec(n));
    
    return 0;
}