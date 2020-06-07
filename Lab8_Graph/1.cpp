#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 20;
int path[N];
vii G[N];

void printPath(int target){
    if (path[target] == -1) return ;
    printPath(path[target]);
    cout << path[target] << "->";
}

void Dijkstra(int start,int target){
    vector<int> dis(N,1000000);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.emplace(0,start);
    dis[start] = 0;
    while(!(pq.empty())){
        int d = pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if (n == target){
            cout << "The distance from " << start << " to " << target << " is " << d << endl;
            cout << "A path from " << start << " to " << target << " is: ";
            printPath(target);
            cout << target << endl << endl;
            break;
        }
        
        for (auto k: G[n]){
            int v = k.first;
            int w = k.second;
            if (dis[n]+w < dis[v]){
                dis[v] = dis[n]+w;
                path[v] = n;
                pq.emplace(dis[v],v);
            }
        }
    }    
}

void makeGraph(){
    int v1 = 5,v2 = 3;
    while (true){
        cin >> v1 >> v2;
        if (v1 == 0 && v2 == 0) break;
        else {
            G[v1].emplace_back(v2,1);
            G[v2].emplace_back(v1,1);
        }
    }
}

void printGraph(int n){
    for (size_t i=1;i<=n;i++){
        cout << i << ": ";
        for (auto k: G[i]) cout << k.first << " ";
        cout << endl;
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
        path[s] = -1;
        Dijkstra(s,f);
        path[s] = 0;
    }
    return 0;
}