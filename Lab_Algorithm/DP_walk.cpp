#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100][100];
vector<int> vi;
int walk(int x,int y){
    if (x == 0 && y == 0) return arr[0][0];
    else {
        if (x == 0) return walk(x,y-1)+arr[x][y];
        else if ( y == 0) return walk(x-1,y)+arr[x][y];
        else {
            return max(walk(x-1,y),walk(x,y-1))+arr[x][y];
            //vi.push_back(best-arr[x][y]);
            //return best;
        }
    }
}

int BU_walk(int x,int y){
    int check[x][y];
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if (check[i][j] == 0)
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for (size_t i=0;i<n;i++){
        for (size_t j=0;j<m;j++) cin >> arr[i][j];
    }
    cout << walk(n-1,m-1) << endl;
    cout << BU_walk(n-1,m-1) << endl;
    return 0;
}