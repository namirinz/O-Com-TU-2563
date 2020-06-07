#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,len=0;
    int arr[205][205];
    char str;
    while (true){
        scanf("%d%d",&n,&m);
        memset(arr,0,sizeof(arr));

        if (n == 0  && m == 0) break;
        if (len != 0) printf("\n");
        len++;
                // y, x
        queue<pair<int,int>> Q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                arr[i][j] = 0;
                scanf(" %c",&str);
                if ( str == '*'){
                    arr[i][j] = -1;
                    Q.emplace(i,j);
                }
            }
        }
        while (!(Q.empty())){
            int i = Q.front().first;
            int j = Q.front().second;
            Q.pop();

            if ( arr[i-1][j-1] != -1 && i > 0 && j > 0) arr[i-1][j-1] += 1;
            if ( arr[i-1][j] != -1 && i > 0) arr[i-1][j] += 1;
            if ( arr[i-1][j+1] != -1 && i > 0 && j < m) arr[i-1][j+1] += 1;
            if ( arr[i][j-1] != -1 && j > 0) arr[i][j-1] += 1;
            if ( arr[i][j+1] != -1 && j < m) arr[i][j+1] += 1;
            if ( arr[i+1][j-1] != -1 && i < n && j > 0) arr[i+1][j-1] += 1;
            if ( arr[i+1][j] != -1 && i < n) arr[i+1][j] += 1;
            if ( arr[i+1][j+1] != -1 && i < n && j < m) arr[i+1][j+1] += 1;
        }
        printf("Field #%d:\n",len);
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++){
                if (arr[i][j] == -1) printf("*");
                else printf("%d",arr[i][j]);
            } 
            printf("\n");
        }
    }
    
    return 0;
}