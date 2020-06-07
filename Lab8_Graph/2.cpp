/*Find the shortest path
    with unweigthed graph or every edges have the same size
    We use BFS to solve this
    PS. The code is simlilar with Dijikstra's Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

const int N = 100;
vi G[N];

void makeGraph(){
    int v1,v2;
    while(true){
        cin >> v1 >> v2;
        if (v1 == 0 && v2 == 0) break;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
}

void printGraph(int n){
    for (size_t i=1;i<=n;i++){
        cout << "node " << i << " : ";
        for (auto k: G[i]) cout << k << " ";
        cout << endl;
    }
}

void printDistance(int start,int finish,int dist){
    cout << "from node " << start << " to " << finish << " is " << dist << endl;
}

void printPath(int path[],int f){
    if (path[f] == -1) return;
    printPath(path,path[f]);
    cout << path[f] << "->";
}

void BFS_STP(int start,int finish){
    int path[N];
    path[start] = -1;
    queue<int> q;
    vector<int> dist(N,N);
    bool isvisited[N];
    q.push(start);
    dist[start] = 0;
    while(!(q.empty())){
        int x = q.front();
        q.pop();
        if (x == finish){
            printDistance(start,finish,dist[x]);
            printPath(path,finish);
            cout << finish;
            cout << endl;
            break;
        }
        if (isvisited[x]) continue;
        for (auto k: G[x]){
            if (!isvisited[k] && dist[x] < dist[k]){
                dist[k] = dist[x]+1;
                path[k] = x;
                q.push(k);
            }
        }
    }
    
}



int main(){
    int n;
    cin >> n;
    makeGraph();
    printGraph(n);

    int s,f;
    while (true){
        cin >> s >> f;
        if (s == 0 && f == 0) break;
        BFS_STP(s,f);
    }
    return 0;
}