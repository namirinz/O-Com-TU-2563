#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    vector<pair<int,int>> G[n+1];
    int num1,num2;
    for (int i=0;i<k;i++){
        scanf("%d %d",&num1,&num2);
        G[num1].emplace_back(num1,num2);
    }
    vector<int> time(n+1,200005);
    time[0] = 0;
    bool check;
    for (int i=0;i<=n;i++){
        if (i != 0) time[i] = min(time[i],time[i-1]+1);
        check = true;
        for (auto k: G[i]){
            time[k.second] = min(time[k.first]+1,time[k.second]);
        }
    }
    printf("%d\n",time[n]);
    if (time[n] <= m) printf("1");
    else {
        for (int i=n;i>=0;i--){
            if (time[i] == m){
                printf("0 %d",i);
                break;
            }
        }
    }

    return 0;
}