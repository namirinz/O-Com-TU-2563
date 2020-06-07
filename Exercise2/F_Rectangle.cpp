#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const long long int &a,const long long int &b){
    return a>b;
}


int main(){
    bool check = true;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long int ans = -1;
    cin >> n;
    long long int vi[n];
    for (int i=0;i<n;i++) cin >> vi[i];
    sort(vi,vi+n,comp);
    long long int l1 = -1;
    for (int i=0;i<n-1;i++){
        if (vi[i] == vi[i+1] && vi[i+1] == vi[i+2] && vi[i+2] == vi[i+3]){
            check = false;
            ans = max(ans,vi[i]*vi[i]);
        }else if (l1 == -1 && vi[i] == vi[i+1]){
            l1 = vi[i];
            i++;
            continue;
        }if ( l1 != -1 && vi[i] == vi[i+1] && vi[i] != l1){
            check = false;
            ans = max(ans,l1*vi[i]);
        }
    }
    if (check) cout << 0;
    else cout << ans;
    return 0;
}