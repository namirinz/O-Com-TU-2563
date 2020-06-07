
#include <bits/stdc++.h>
using namespace std;

int p[200001];
int findRoot(int u){
    if (p[u] == u) return u;
    else {
        return p[u] = findRoot(p[u]);
        //int ret = findRoot(p[u]);
        //p[u] = ret;
        //return ret;
    }
}
int rnk[200001];
void unionSet(int a,int b){
    a = findRoot(a);
    b = findRoot(b);
    if ( a == b) return;
   
   if ( rnk[a] > rnk[b]){
       rnk[a] += rnk[b];
       p[b] = a;
   }else {
       rnk[b] += rnk[a];
       p[a] = b;
   }
}

int main(){
    int dist;
    int n = 1,m = 2;
    int v1,v2,w;
    while (true){
        memset(p, 0, sizeof(p));
        for (int i=0;i<=200000;i++) {
            p[i] =i;
            rnk[i] = 1;
        }
        cin >> n >> m;
        if ( n == 0 && m == 0) break;
        else {
            vector<tuple<int,int,int>> edges;
            for (int i=0;i<m;i++){
                cin >> v1 >> v2 >> w;
                //p[v1] = v1;
                //p[v2] = v2;
                edges.push_back(make_tuple(w,v1,v2));
            }
            dist = 0;
            sort(edges.begin(),edges.end());
            for (auto k: edges){
                int w1 = get<0>(k);
                int n1 = get<1>(k);
                int n2 = get<2>(k);

                if ( findRoot(n1) != findRoot(n2)) {
                    dist += w1;
                    unionSet(n1,n2);}
            }
            cout << dist << endl;
        }
    }
    return 0;
}