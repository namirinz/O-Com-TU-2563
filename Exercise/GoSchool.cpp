#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> v;

int dist1=0;
short int mem[51][51];
void walk2(int x,int y){
    if ( x == 1 && y == 1) {
        dist1++;
        mem[x][y] = 1;
        return;
    }
    else if (mem[x][y] == -1){
        return;
    }
    else if (mem[x][y] == 1 ){
        dist1++;
        return;
    }
    else {
        for (auto k: v){
            if (k.first == x && k.second == y){
                mem[x][y] = -1;
                return;
            }           
        }
        if ( x == 1 ) walk2(x,y-1);
        else if ( y == 1) walk2(x-1,y);
        else {
            walk2(x-1,y);
            walk2(x,y-1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a,x,y;
    cin >> a;
    for (int i=0;i<a;i++){
        cin >> x >> y;
        v.emplace_back(x,y);
    }
    walk2(n,m);
    cout << dist1;
    return 0;
}   