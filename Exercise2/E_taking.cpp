#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[25];

ll recur(int i,ll m,ll value){   
    if (i == 0 ) return value;
    ll ans = 0;
    if ( m >= arr[i-1] ){
        ans = max(ans,recur(i-1,m-arr[i-1],value+arr[i-1]));
    }ans = max(ans,recur(i-1,m,value));
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> t;
    ll m;
    for(int i=0;i<t;i++){
        memset(arr,0,sizeof(arr));
        cin >> n >> m;
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        cout << recur(n,m,0) << endl;
    }

    return 0;
}