#include <iostream>
using namespace std;
int v[100000],w[100000];
int Knapsack(int n,int w2){
    if ( n == 0 || w2 == 0) return 0;
    else if (w2 >= w[n]) return max(Knapsack(n-1,w2),Knapsack(n-1,w2-w[n])+v[n]);
    else return Knapsack(n-1,w2);
}

int p[10000][10000];
int TD_Knapsack(int n,int w2){
    if (n == 0 || w2 == 0) return 0;
    else if (w2 >= w[n]){
        p[n][w2] = max(Knapsack(n-1,w2),Knapsack(n-1,w2-w[n])+v[n]);
    }else {
        p[n][w2] = Knapsack(n-1,w2);
    }
    return p[n][w2];
}

int BU_Knapsack(int n,int w2){
    int p2[n+1][w2+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j <= w2;j++){
            if ( i==0 || j == 0) p2[i][j] = 0;
            else if (j >= w[i]){
                p2[i][j] = max(p2[i-1][j],p2[i-1][j-w[i]]+v[i]);
            }else {
                p2[i][j] = p2[i-1][j];
            }
        }
    }
    return p2[n][w2];
}

int main(){
    int n,w2;
    cin >> n >> w2;
    
    for (int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    cout << Knapsack(n-1,w2) << endl;
    cout << TD_Knapsack(n-1,w2) << endl;
    cout << BU_Knapsack(n-1,w2) << endl;
    return 0;
}