#include <iostream>
using namespace std;

/*
4 6
7 4 10 15 3 18
21 20 5 11 30 17
25 3 21 25 2 6
29 4 1 12 18 19
*/

int main(){
    int n,m;
    cin >> n >> m;
    int arr1[n][m];
    int arr2[n+1][m+1];
    
    int i,j;
    int num;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            cin >> num;
            arr1[i][j] = num;            
        }
    }
    for ( i=0;i<=n;i++ ){
        for (j=0;j<=m;j++){
            if (i == 0 || j == 0) arr2[i][j] = 0;
            else {
                arr2[i][j] = arr2[i-1][j]+arr2[i][j-1]+arr1[i-1][j-1]-arr2[i-1][j-1];
            }
            cout << arr2[i][j] << " ";
        }cout << endl;
    }

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << arr2[x2+1][y2+1]-arr2[x2+1][y1]-arr2[x1][y2+1]+arr2[x1][y1];
    return 0;
}