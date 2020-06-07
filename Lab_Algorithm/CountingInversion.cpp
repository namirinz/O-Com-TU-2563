#include <iostream>
using namespace std;
typedef int ll;
ll arr[500001];
ll Conquere(ll left,ll mid,ll right){
    ll count = 0;
    ll i = left;
    ll j = mid;
    ll k = left;
    ll T[500001];
    while (i <= mid-1 && j <= right){
        if (arr[i] < arr[j]) T[k++] = arr[i++];
        else {
            T[k++] = arr[j++];
            cout << " Here " << arr[i] << " " << arr[j] << "\n";
            count += (mid-i);
        }
    }
    while (i <= mid-1) T[k++] = arr[i++];
    while (j <= right) T[k++] = arr[j++];

    for (ll loop = left;loop<=right; loop++){
        arr[loop] = T[loop];
    }
    return count;
}

ll Divide(ll left,ll right){
    ll count = 0,mid;
    if ( left < right){
        mid = (left+right)/2;
        count = Divide(left,mid);
        count += Divide(mid+1,right);
        count += Conquere(left,mid+1,right);
    }
    return count;
}

int main(){
    ll n;
    while (true){
        cin >> n;
        if ( n == 0) break;
        for (ll i=0;i<n;i++) cin >> arr[i];
        ll ans = Divide(0,n-1);
        cout << ans << endl;
        for (int i=0;i<n;i++) cout << arr[i] << " ";
    }
    return 0;
}