#include <iostream>
using namespace std;
typedef long long int ll;
int v[1000];
ll w[1000];

ll Knapsack(int n, ll m){
    ll mem[n+1][m+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if ( i == 0 || j == 0) mem[i][j] = 0;
            else if ( j >= w[i-1]) mem[i][j] = max(mem[i-1][j],mem[i-1][j-w[i-1]]+v[i-1]);
            else mem[i][j] = mem[i-1][j];
        }
    }return mem[n][m];
}


int main(){
    int n,w2;
    cin >> n >> w2;
    for (ll i=0;i<n;i++) cin >> w[i] >> v[i];
    cout << Knapsack(n,w2);
    return 0;
}