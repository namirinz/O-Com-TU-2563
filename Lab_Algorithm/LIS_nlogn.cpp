#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int arr[105],n;

int LIS(int i){
    set<int> T;
    T.insert(arr[0]);
    for (int i=1;i<n;i++){
        auto it = T.upper_bound(arr[i]);
        if (it == T.end()) T.insert(arr[i]);
        else {
            int val = *it;
            if ( val > arr[i]){
                T.erase(it);
                T.insert(arr[i]);
            }
        }
    }
    return T.size();
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << LIS(0);
    return 0;
}