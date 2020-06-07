#include <iostream>
using namespace std;

int binomial(int n,int k){
    if (k == 0 || n == k) return 1;
    return binomial(n-1,k-1)+binomial(n-1,k);
}

int p[10000][10000];
int TD_binomial(int n,int k){
    if (k == 0 || n == k) return 1;
    else {
        p[n-1][k-1] = binomial(n-1,k-1);
        p[n-1][k] = binomial(n-1,k);
        return p[n][k] = p[n-1][k-1]+p[n-1][k];
    }
}

int p2[10000][10000];
int BU_binomial(int n,int k){
    for (int i=0;i<=n;i++){
        for (int j=0;j<=i;j++){
            if (j == 0 || i == j) p[i][j] = 1;
            else {
                p[i][j] = p[i-1][j-1]+p[i-1][j];
            }
        }
    }
    return p[n][k];
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << binomial(n,k) << endl;
    cout << TD_binomial(n,k) << endl;
    cout << BU_binomial(n,k) << endl;
    return 0;
}