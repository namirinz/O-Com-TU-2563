#include <iostream>
using namespace std;
int n,m;
int arr[25];


int mem[10000][10000];
int recur2(int i,int val){
    if ( val > m ) {
        mem[i][val] = -arr[i-1];
        return mem[i][val];
    }else if (val == m){
        mem[i][val] = 0;
        return mem[i][val];
    }else if (i == n){
        mem[i][val] = 0;
        return mem[i][val];
    }else {
        mem[i][val] = max(recur2(i+1,val+arr[i])+arr[i],recur2(i+1,val));
        return mem[i][val];
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m;
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        n--;
        cout << recur2(0,0) << endl;
    }
    return 0;
}