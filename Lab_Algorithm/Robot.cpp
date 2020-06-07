#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
int arr[2001][2001];
bool isvisited[2001][2001];
int main(){
    int n,m;
    char s;
    scanf("%d %d",&n,&m);
    int max1 = 9999999;
    queue<ii> Start;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf(" %c",&s);
            if (s == 'W') arr[i][j] = -1;
            else if (s == 'A') {arr[i][j] = max1;}
            else if (s == 'X'){
                arr[i][j] = -2;
                Start.emplace(j,i);
            }
        }
    }
    int ans = 0,total = 0;
    while (!Start.empty()){
        queue<iii> PQ;
        memset(isvisited,0,sizeof(isvisited));
        PQ.emplace(0,Start.front().first,Start.front().second);
        Start.pop();
        while (!PQ.empty()){
            int lev = get<0>(PQ.front());
            int x = get<1>(PQ.front());
            int y = get<2>(PQ.front());
            PQ.pop();


            if (isvisited[y][x]) continue;
            
            isvisited[y][x] = true;
            if (arr[y][x] != -1 && arr[y][x] != -2 && arr[y][x] != 0){
                if (arr[y][x] == max1) {
                    total++;
                    arr[y][x] = lev+lev;
                    ans += lev+lev;
                }else if ( lev+lev < arr[y][x]){
                    ans -= arr[y][x];
                    arr[y][x] = lev+lev;
                    ans += lev+lev;
                }
            }
            if (arr[y-1][x] != -1 && !isvisited[y-1][x] && y > 0){
                PQ.emplace(lev+1,x,y-1);
            }if ( !isvisited[y][x-1] && x > 0 && arr[y][x-1] != -1){
                PQ.emplace( lev+1,x-1,y);
            }if ( !isvisited[y][x+1] && x < m-1 && arr[y][x+1] != -1){
                PQ.emplace(lev+1,x+1,y);
            }if ( !isvisited[y+1][x]  && y < n-1 && arr[y+1][x] != -1){
                PQ.emplace(lev+1,x,y+1);
            }
        }
    }
    printf("%d %d",total,ans);


    return 0;
}